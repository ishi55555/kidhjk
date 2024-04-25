#include <iostream>
using namespace std;

// Merge two sorted subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
    // Determine sizes of subarrays L and M
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary arrays L and M
    int L[n1], M[n2];

    // Copy data to temporary arrays L[] and M[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Merge the temporary arrays back into arr[p..r]

    // Initial indexes of subarrays L and M
    int i = 0, j = 0;
    
    // Initial index of merged subarray arr[p..r]
    int k = p;

    // Until we reach either end of either L or M,
    // pick the smaller element from L and M and place
    // it into arr[p..r] at correct position
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L, if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of M, if any
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Function to recursively divide the array into subarrays, sort them, and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point to divide the array into two halves
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to print the elements of the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Call the mergeSort function to sort the array
    mergeSort(arr, 0, size - 1);

    // Print the sorted array
    cout << "Sorted array: \n";
    printArray(arr, size);

    return 0;
}

//O(N log N)