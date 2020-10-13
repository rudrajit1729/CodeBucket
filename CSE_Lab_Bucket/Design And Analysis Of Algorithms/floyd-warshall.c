// Floyd Warshall Algorithm 

#include<stdio.h> 
#include<limits.h>

#define INF INT_MAX 

//No. of vertices declared global
int V;

//prints the solution matrix 
void printSolution(int dist[][V]) 
{ 
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n"); 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				printf("%7s", "INF"); 
			else
				printf ("%7d", dist[i][j]); 
		} 
		printf("\n"); 
	} 
} 

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm 
void floydWarshall (int graph[][V]) 
{ 
	/* dist[][] will be the output matrix that will finally have the shortest 
	distances between every pair of vertices */
	int dist[V][V], i, j, k; 

	/* the initial values of shortest distances are 
	shortest paths considering no intermediate vertex. */
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 

	/* Add all vertices one by one to the set of intermediate vertices. 
	---> Before start of an iteration, we have shortest distances between all 
	pairs of vertices such that the shortest distances consider only the 
	vertices in set {0, 1, 2, .. k-1} as intermediate vertices. 
	---> After the end of an iteration, vertex no. k is added to the set of 
	intermediate vertices and the set becomes {0, 1, 2, .. k} */
	for (k = 0; k < V; k++) 
	{ 
		// Pick all vertices as source one by one 
		for (i = 0; i < V; i++) 
		{ 
			// Pick all vertices as destination for the above picked source  
			for (j = 0; j < V; j++) 
			{ 
				// If vertex k is on the shortest path from 
				// i to j, then update the value of dist[i][j] 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	// Print the shortest distance matrix 
	printSolution(dist); 
} 


int main()
{
	int i,j;
	printf("\nEnter number of vertices:");
	scanf("%d",&V);
	int graph[V][V];
	printf("\nEnter the adjacency matrix for the graph(Enter -1 if distance is INF)\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			dist = 0;
			scanf("%d",&dist);
			if (dist == -1){dist = INF;}
			graph[i][j] = dist;
		}

	}
	//Print the solution
	floydWarshall(graph);
	return 0;
}
