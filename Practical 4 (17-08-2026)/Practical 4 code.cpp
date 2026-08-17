

#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    int n, capacity;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    // Input items
    printf("\nEnter weight and profit of each item:\n");

    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &item[i].weight, &item[i].profit);

        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("\nEnter knapsack capacity: ");
    scanf("%d", &capacity);

    // Find minimum and maximum profit and ratio
    int minProfit = item[0].profit;
    int maxProfit = item[0].profit;
    float minRatio = item[0].ratio;
    float maxRatio = item[0].ratio;

    for (int i = 1; i < n; i++) {

        if (item[i].profit < minProfit)
            minProfit = item[i].profit;

        if (item[i].profit > maxProfit)
            maxProfit = item[i].profit;

        if (item[i].ratio < minRatio)
            minRatio = item[i].ratio;

        if (item[i].ratio > maxRatio)
            maxRatio = item[i].ratio;
    }

    // Display minimum and maximum values
    printf("\nMinimum Profit = %d", minProfit);
    printf("\nMaximum Profit = %d", maxProfit);
    printf("\nMinimum Profit Ratio = %.2f", minRatio);
    printf("\nMaximum Profit Ratio = %.2f\n", maxRatio);

    // Sort items according to profit/weight ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    // Fractional Knapsack
    for (int i = 0; i < n; i++) {

        if (capacity >= item[i].weight) {
            capacity = capacity - item[i].weight;
            totalProfit = totalProfit + item[i].profit;
        }
        else {
            float fraction = (float)capacity / item[i].weight;

            totalProfit = totalProfit +
                          (item[i].profit * fraction);

            capacity = 0;
            break;
        }
    }

    printf("\nMaximum Profit using Fractional Knapsack = %.2f\n",
           totalProfit);

    return 0;
}