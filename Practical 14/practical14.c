// Aim: find the Optimal Binary Search Tree (OBST) using Dynamic Programming
#include <stdio.h>

#define N 4

int main() {
    int keys[N] = {10, 20, 30, 40};
    int freq[N] = {4, 2, 6, 3};
    int cost[N][N];

    for (int i = 0; i < N; i++) cost[i][i] = freq[i];

    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            cost[i][j] = 9999;
            int fsum = 0;
            for (int k = i; k <= j; k++) fsum += freq[k];

            for (int r = i; r <= j; r++) {
                int left = (r > i) ? cost[i][r - 1] : 0;
                int right = (r < j) ? cost[r + 1][j] : 0;
                int total = left + right + fsum;
                if (total < cost[i][j]) cost[i][j] = total;
            }
        }
    }

    printf("Keys:  ");
    for (int i = 0; i < N; i++) printf("%d ", keys[i]);
    printf("\nFreqs: ");
    for (int i = 0; i < N; i++) printf("%d ", freq[i]);
    printf("\n\nMinimum cost of Optimal BST = %d\n", cost[0][N - 1]);
    return 0;
}
