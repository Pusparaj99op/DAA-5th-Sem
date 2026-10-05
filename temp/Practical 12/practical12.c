// Aim: find the Longest Common Subsequence (LCS) of two strings
#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "ABCBDAB";
    char b[] = "BDCABA";
    int m = strlen(a), n = strlen(b);
    int dp[50][50];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = (i == 0 || j == 0) ? 0 :
                (a[i - 1] == b[j - 1]) ? dp[i - 1][j - 1] + 1
                                       : (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);

    int len = dp[m][n];
    char lcs[50];
    lcs[len] = '\0';
    int i = m, j = n, k = len;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) { lcs[--k] = a[i - 1]; i--; j--; }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }

    printf("String 1: %s\n", a);
    printf("String 2: %s\n", b);
    printf("LCS length = %d\n", len);
    printf("LCS string = %s\n", lcs);
    return 0;
}
