
#include <stdio.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    // Initialize the dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored in the last cell
    return dp[n][capacity];
}

int main() {
    int size = 3;
    int max_val;
    int values[3] = {60, 100, 120};
    int weights[3] = {10, 20, 30};
    int capacity = 50;

    max_val = knapsack(capacity, weights, values, size);
    printf("Knapsack max value is %d", max_val);

    return 0;
}

