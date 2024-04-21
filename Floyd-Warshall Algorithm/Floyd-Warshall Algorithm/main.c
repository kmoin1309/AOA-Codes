//
//  main.c
//  Floyd-Warshall Algorithm
//
//  Created by Md Moinuddin Quazi on 4/21/24.
//

#include <stdio.h>
#define INF 99
void floyd_warshall(int graph[][100], int V) {
    int dist[100][100], i, j, k;
    // Initialize the distance matrix with the adjacency matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    // Calculate the shortest path for each pair of vertices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Print the shortest distance matrix
    printf("Shortest distance matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
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
    int V, i, j;
    int graph[100][100];
    // Get the number of vertices from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    // Get the adjacency matrix from the user
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == INF) {
                graph[i][j] = INF;
            }
        }
    }
    // Run the Floyd-Warshall algorithm
    floyd_warshall(graph, V);
    return 0;
}
