// Aim: implement Floyd-Warshall algorithm (all-pairs shortest path)
#include <stdio.h>

#define V 4
#define INF 9999

void printMatrix(int m[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (m[i][j] == INF) printf("%6s", "INF");
            else printf("%6d", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    printf("Input adjacency matrix:\n");
    printMatrix(graph);

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (graph[i][k] != INF && graph[k][j] != INF &&
                    graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

    printf("\nShortest distance matrix:\n");
    printMatrix(graph);

    return 0;
}
