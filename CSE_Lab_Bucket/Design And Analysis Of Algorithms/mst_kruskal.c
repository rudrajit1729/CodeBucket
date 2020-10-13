// Minimum spanning tree using Kruskal's algo with the aid of set operations

#include <stdio.h>
#include <stdlib.h>

struct set{
    struct set *p;
    int rank;
};

struct vertex{
    struct set *v;
    int num;
};

struct edge{
    struct vertex *u;
    struct vertex *v;
    int wt;
};

struct graph{
    int v;
    int e;
} G;

void makeSet(struct set *x)
{
    x->p = x;
    x->rank = 0;
}

struct set *findSet(struct set *x)
{
    if (x != x->p)
        x->p = findSet(x->p);
    return x->p;
}

void link(struct set *x, struct set *y)
{
    if (x->rank > y->rank)
        y->p = x;
    else {
        x->p = y;
        if (x->rank == y->rank)
            y->rank += 1;
    }
}

void unionSet(struct set *x, struct set *y)
{
    link(findSet(x), findSet(y));
}

// int comp(const void *p, const void *q)
// {
//     struct edge *l = (struct edge *)p;
//     struct edge *r = (struct edge *)q;
//     return ((l->wt) - (r->wt));
// }

void mstKruskal(int e, struct edge *edges[e])
{
    for (int i = 0; i < e-1; i++) {
        for (int j = 0; j < e-i-1; j++) {
            if (edges[j]->wt > edges[j+1]->wt) {
                struct edge *t = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = t;
            }
        }
    }
    // qsort(edges, e, sizeof(struct edge), comp);

    int sum = 0;
    printf("\n");
    for (int i = 0; i < G.e; i++) {
        if (findSet(edges[i]->u->v) != findSet(edges[i]->v->v)) {
            printf("%5d %5d %5d\n", edges[i]->u->num, edges[i]->v->num, edges[i]->wt);
            sum += edges[i]->wt;
            unionSet(edges[i]->u->v, edges[i]->v->v);
        }
    }
    printf("%d", sum);
}

int main()
{
    int stv, edv, w;
    printf("No. of vertices: ");
    scanf("%d", &G.v);
    printf("No. of edges: ");
    scanf("%d", &G.e);
    struct edge *edges[G.e];
    struct vertex *vertices[G.v];
    for (int i = 0; i < G.v; i++)
        vertices[i] = malloc(sizeof(struct vertex));
    for (int i = 0; i < G.e; i++)
        edges[i] = malloc(sizeof(struct edge));
    for (int i = 0; i < G.v; i++) {
        vertices[i]->v = malloc(sizeof(struct set));
        makeSet(vertices[i]->v);
        vertices[i]->num = i;
    }
    for (int i = 0; i < G.e; i++) {
        scanf("%d %d %d", &stv, &edv, &w);
        edges[i]->u = vertices[stv];
        edges[i]->v = vertices[edv];
        edges[i]->wt = w;
    }
    printf("\nSolution minimum spanning tree\n");
    printf("Start    End    Weight");
    mstKruskal(G.e, edges);
    return 0;
}
