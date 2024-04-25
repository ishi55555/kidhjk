#include <bits/stdc++.h>

using namespace std;

struct Item {
   int value; // Value of the item
   int weight; // Weight of the item
};

class Solution {
   public:
      // Comparator function to sort items in descending order of value/weight ratio
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight; // Calculate ratio for item a
         double r2 = (double) b.value / (double) b.weight; // Calculate ratio for item b
         return r1 > r2; // Sort in descending order of ratio
      }

      // Function to solve fractional knapsack problem
      double fractionalKnapsack(int W, Item arr[], int n) {
         // Sort items based on value/weight ratio
         sort(arr, arr + n, comp);

         int curWeight = 0; // Current total weight in knapsack
         double finalvalue = 0.0; // Final total value of items in knapsack

         for (int i = 0; i < n; i++) {
            // If adding the entire item won't exceed knapsack capacity
            if (curWeight + arr[i].weight <= W) {
               curWeight += arr[i].weight; // Add item's weight to knapsack
               finalvalue += arr[i].value; // Add item's value to final value
            } else {
               int remain = W - curWeight; // Remaining capacity in knapsack
               // Add fractional part of item to knapsack
               finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
               break; // Knapsack is full, exit loop
            }
         }

         return finalvalue; // Return final total value of items in knapsack
      }
};

int main() {
   int n = 3, weight = 50; // Number of items and weight capacity of knapsack
   Item arr[n] = { {100,20},{60,10},{120,30} }; // Array of items with value and weight
   Solution obj; // Create Solution object
   double ans = obj.fractionalKnapsack(weight, arr, n); // Call fractionalKnapsack function
   cout << "The maximum value is " << setprecision(2) << fixed << ans; // Output maximum value
   return 0;
}

//O(nlogn)
