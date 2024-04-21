//
//  index.c
//  Minimum-Cost-Spanning-Tree
//
//  Created by Md Moinuddin Quazi on 4/21/24.
//

#include <stdio.h>

#define MAX_NODES 10
#define INF 999

int main() {
    int cost[MAX_NODES][MAX_NODES];
    int visited[MAX_NODES] = {0};
    int mincost = 0;
    int n, ne = 1;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[1] = 1;
    printf("\n");

    while (ne < n) {
        int min = INF;
        int a = -1, b = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("Edge %d: (%d %d) cost: %d\n", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        } else {
            printf("No minimum-cost edge found.\n");
            break;
        }
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}


