// write a program C to implement floyd warshall algorithm , to find the shorestest disncaces between every pair of vertices in a weightded graph, taking input from user
#include <stdio.h>
#include <stdlib.h>

// Define a large value to represent infinity (no direct edge exists)
#define INF 999999

// Function prototype to run the Floyd-Warshall algorithm
void floydWarshall(int **matrix, int vertices);
void printMatrix(int **matrix, int vertices);

int main() {
    int vertices;

    printf("==================================================\n");
    printf("   Floyd-Warshall All-Pairs Shortest Path Program \n");
    printf("==================================================\n");

    // 1. Get the number of vertices from the user
    printf("Enter the number of vertices in the graph: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    // 2. Dynamically allocate memory for the adjacency matrix
    int **graph = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int *)malloc(vertices * sizeof(int));
    }

    // 3. Take weight matrix inputs from the user
    printf("\nEnter the adjacency matrix (%d x %d):\n", vertices, vertices);
    printf("Use 0 for self-loops and '%d' if there is no direct edge between vertices.\n\n", INF);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("Weight from Vertex %d to Vertex %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n--- Input Graph Representation ---\n");
    printMatrix(graph, vertices);

    // 4. Execute the algorithm
    floydWarshall(graph, vertices);

    // 5. Free dynamically allocated memory
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

void floydWarshall(int **matrix, int vertices) {
    // Three nested loops:
    // The outer loop (k) selects the intermediate vertex.
    // The inner loops (i, j) scan every pair of source and destination vertices.
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                // If vertex k is on the shortest path from i to j,
                // and paths through k are valid (not infinity), update the value of matrix[i][j]
                if (matrix[i][k] != INF && matrix[k][j] != INF &&
                    (matrix[i][k] + matrix[k][j] < matrix[i][j])) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    // Print the final calculated shortest path matrix
    printf("\n--- Shortest Distance Matrix Between Every Pair ---\n");
    printMatrix(matrix, vertices);
}

void printMatrix(int **matrix, int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (matrix[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}