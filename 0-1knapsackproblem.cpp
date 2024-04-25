#include <iostream>
#include <vector>
using namespace std;

// Function to solve the knapsack problem using memoization
int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int> >& dp) {
    // Base case: if all items are processed or if capacity becomes 0
    if (index == n || capacity == 0) {
        return 0;
    }

    // If the result for this capacity and index is already calculated, return it
    if (dp[capacity][index] != -1) {
        return dp[capacity][index];
    }

    // Include current item if its weight is less than or equal to the capacity
    int include = 0;
    if (wt[index] <= capacity) {
        // Calculate profit by including the current item and recursively solving for remaining capacity and items
        include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, index + 1, n, dp);
    }

    // Exclude current item and recursively solve for remaining items
    int exclude = solveUsingMem(capacity, wt, profit, index + 1, n, dp);

    // Choose the maximum profit between including and excluding the current item
    dp[capacity][index] = max(include, exclude); // Store the result in dp table

    return dp[capacity][index]; // Return the maximum profit
}

int main() {
    int capacity = 50; // Knapsack capacity
    int wt[] = {10,20,30}; // Weight of items
    int profit[] = {60,100,120}; // Profit of items
    int n = 3; // Number of items

    // Create a 2D vector to store intermediate results for memoization
    vector<vector<int> > dp(capacity + 1, vector<int>(n, -1));

    // Call the function to solve knapsack problem using memoization
    int ans = solveUsingMem(capacity, wt, profit, 0, n, dp);

    // Output the maximum profit
    cout << "Max Profit: " << ans << endl;

    return 0;
}

//O(n⋅W)
