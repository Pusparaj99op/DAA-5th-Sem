// Aim: implement the N-Queens puzzle using Backtracking
#include <stdio.h>

#define N 4
int board[N][N];

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return 0;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return 0;
    return 1;
}

int solve(int row) {
    if (row == N) return 1;
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            if (solve(row + 1)) return 1;
            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    printf("N-Queens solution for N = %d\n\n", N);
    if (solve(0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf(" %c", board[i][j] ? 'Q' : '.');
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }
    return 0;
}
