//Amin: write a program C to implement floyd warshall algorithm , to find the shorestest disncaces between every pair of vertices in a weightded graph


#include <stdio.h>

// Define the number of vertices in the graph
#define V 4

// Use a large value to represent infinity (no direct edge between vertices)
// Choose a value that won't cause integer overflow when adding two distances
#define INF 99999

// Function prototype to print the solution matrix
void printSolution(int dist[][V]);

// Implements the Floyd-Warshall All-Pairs Shortest Path algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V];
    int i, j, k;

    // Step 1: Initialize the solution matrix with the input graph's weights
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Core Algorithm
    // Consider every vertex 'k' as an intermediate point one by one
    for (k = 0; k < V; k++) {
        // Pick all vertices as source 'i' one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination 'j' for the source 'i'
            for (j = 0; j < V; j++) {
                // If vertex k is an intermediate point on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && (dist[i][k] + dist[k][j] < dist[i][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print the final shortest distance matrix
    printSolution(dist);
}

/* A utility function to print the solution matrix */
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         ^
      5 |         | 1
        v         |
       (1)------->(2)
            3           */
    int graph[V][V] = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    // Run the algorithm
    floydWarshall(graph);

    return 0;
}