// Aim: solve the Travelling Salesman Problem using Dynamic Programming
#include <stdio.h>

#define N 4
#define INF 9999

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};
int dp[1 << N][N];

int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) return dist[pos][0];
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < N; city++) {
        if (!(mask & (1 << city))) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans) ans = newAns;
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    printf("Distance matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%5d", dist[i][j]);
        printf("\n");
    }

    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    int minCost = tsp(1, 0);
    printf("\nMinimum cost of TSP tour starting at city 0 = %d\n", minCost);
    return 0;
}
