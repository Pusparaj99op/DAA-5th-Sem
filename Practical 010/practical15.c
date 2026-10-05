// Aim: solve the Sum of Subsets problem using Backtracking
#include <stdio.h>

#define N 5
int set[N] = {10, 7, 5, 18, 3};
int subset[N];
int target = 25;
int found = 0;

void printSubset(int k) {
    printf("Subset found: { ");
    for (int i = 0; i < k; i++) printf("%d ", subset[i]);
    printf("}\n");
    found = 1;
}

void sumOfSubsets(int i, int currSum, int k) {
    if (currSum == target) {
        printSubset(k);
        return;
    }
    if (i == N || currSum > target) return;

    subset[k] = set[i];
    sumOfSubsets(i + 1, currSum + set[i], k + 1);
    sumOfSubsets(i + 1, currSum, k);
}

int main() {
    printf("Set: { ");
    for (int i = 0; i < N; i++) printf("%d ", set[i]);
    printf("}\n");
    printf("Target sum = %d\n\n", target);

    sumOfSubsets(0, 0, 0);

    if (!found) printf("No subset with the given sum exists\n");
    return 0;
}
