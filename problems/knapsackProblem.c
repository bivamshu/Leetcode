#include <stdio.h>

// A utility function that returns the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0; // Base case: 0 items or 0 capacity
            } else if (wt[i - 1] <= w) {
                // Max of including the item or excluding it
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                // Item is too heavy, exclude it
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W]; // The bottom-right corner holds the maximum value
}

int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(W, weight, profit, n));
    return 0;
}