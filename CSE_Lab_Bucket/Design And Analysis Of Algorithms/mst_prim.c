#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct vertex {
    int num;
    int key;
    struct vertex *p;
};

struct graph {
    int v;
    int e;
} G;

void minHeapify(int v, struct vertex *q[v], int i)
{
    int smallest;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if ((l < v) && (q[l]->key < q[i]->key))
        smallest = l;
    else
        smallest = i;
    if ((r < v) && (q[r]->key < q[smallest]->key))
        smallest = r;
    if (smallest != i) {
        struct vertex *t = q[i];
        q[i] = q[smallest];
        q[smallest] = t;
        minHeapify(v, q, smallest);
    }
}

struct vertex *extractMin(int v, struct vertex *q[v])
{
    if (v < 0)
        printf("Heap underflow\n");
    struct vertex *min = q[0];
    q[0] = q[v-1];
    q[v-1] = min;
    v--;
    minHeapify(v, q, 0);
    return min;
}

void decreaseKey(int v, struct vertex *q[v], int i, int key)
{
    if (key > q[i]->key)
        printf("New key is greater than current key\n");
    q[i]->key = key;
    int p;
    if (i%2 == 0)
        p = i/2-1;
    else
        p = i/2;
    while ((i > 0) && (q[p]->key > q[i]->key)) {
        struct vertex *t = q[i];
        q[i] = q[p];
        q[p] = t;
        i = p;
        if (i%2 == 0)
            p = i/2-1;
        else
            p = i/2;
    }
}

int isInQ(int j, int v, struct vertex *q[v])
{
    for (int i = 0; i < v; i++) {
        if (q[i]->num == j)
            return i;
    }
}

void mstPrim(int v, struct vertex *q[v], int r, int a[v][v])
{
    q[r]->key = 0;
    if (r != 0) {
        struct vertex *t = q[r];
        q[r] = q[0];
        q[0] = t;
    }
    int sum = 0, i = v, c;
    while (i > 0) {
        struct vertex *u = extractMin(i, q);
        i--;
        for (int j = 0; j < v; j++) {
            if (a[u->num][j] < INT_MAX) {
                c = isInQ(j, v, q);
                if ((c < i) && (a[u->num][j] < q[c]->key)) {
                    q[c]->p = u;
                    decreaseKey(i, q, c, a[u->num][j]);
                }
            }
        }
    }
    printf("\n");
    for (int i = 0; i < v-1; i++) {
        printf("%5d %5d %5d\n", q[i]->p->num, q[i]->num, q[i]->key);
        sum += q[i]->key;
    }
    printf("%d", sum);
}

int main()
{
    int stv, edv, w, st;
    printf("No. of vertices: ");
    scanf("%d", &G.v);
    printf("No. of edges: ");
    scanf("%d", &G.e);
    int a[G.v][G.v];
    struct vertex *q[G.v];
    for (int i = 0; i < G.v; i++) {
        q[i] = malloc(sizeof(struct vertex));
        q[i]->num = i;
        q[i]->key = INT_MAX;
        q[i]->p = NULL;
    }
    for (int i = 0; i < G.v; i++) {
        for (int j = 0; j < G.v; j++) {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < G.e; i++) {
        scanf("%d %d %d", &stv, &edv, &w);
        a[stv][edv] = w;
        a[edv][stv] = w;
    }
    printf("Which is the start vertex? ");
    scanf("%d", &st);
    printf("\nSolution minimum spanning tree\n");
    printf("Start    End    Weight");
    mstPrim(G.v, q, st, a);
    return 0;
}
