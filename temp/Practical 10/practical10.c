// Aim: solve the Job Sequencing problem using a greedy strategy
#include <stdio.h>

struct Job { char id; int deadline, profit; };

int main() {
    struct Job jobs[] = {
        {'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27},
        {'D', 1, 25}, {'E', 3, 15}
    };
    int n = 5, maxDeadline = 3;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job t = jobs[j]; jobs[j] = jobs[j + 1]; jobs[j + 1] = t;
            }

    int slot[10] = {0};
    char result[10];
    int totalProfit = 0, jobCount = 0;

    for (int i = 0; i < n; i++) {
        for (int t = jobs[i].deadline; t > 0; t--) {
            if (t <= maxDeadline && slot[t] == 0) {
                slot[t] = 1;
                result[jobCount++] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Jobs (id, deadline, profit) sorted by profit:\n");
    for (int i = 0; i < n; i++)
        printf("  %c  d=%d  p=%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);

    printf("\nScheduled jobs: ");
    for (int i = 0; i < jobCount; i++) printf("%c ", result[i]);
    printf("\nTotal profit = %d\n", totalProfit);
    return 0;
}
