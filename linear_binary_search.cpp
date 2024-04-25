#include<bits/stdc++.h>
#include<cstdlib>
#include<iostream>
#include<chrono>
#include <iomanip>  // for setprecision

using namespace std;

int linearSearch(long long int arr[], long int n, long int ele) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == ele)
            return i;
    }
    
    return -1;
}

int recursiveLinearSearch(long long int arr[], int size, int key)
{
    if (size == 0) {
        return -1;
    }
    else if (arr[size - 1] == key) {
        
        // Return the index of found key.
        return size - 1;
    }
    return recursiveLinearSearch(arr, size - 1, key);
}

int binarySearchIterative(long long int arr[], long int n, long int ele) {
    int low = 0, high = n-1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if(ele == arr[mid])
            return mid;
        
        else if(ele < arr[mid])
            high = mid - 1;
        
        else
            low = mid + 1;
    }
    
    return -1;
}

int binarySearchRecursive(long long int arr[], int low, int high, long int ele) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == ele)
            return mid;

        if (ele < arr[mid])
            return binarySearchRecursive(arr, low, mid - 1, ele);

        return binarySearchRecursive(arr, mid + 1, high, ele);
    }

    return -1;
}

int main() {
    srand((unsigned) time(NULL));
    
    cout << fixed;
    
    long int n, ele;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    
    long long int* arr = new long long int[n];
    
    for(int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    
    ele = arr[rand() % n];
    
    cout << "\nThe element to be searched is: " << ele;
    
    // Linear Search
    cout << "\n=== ITERATIVE LINEAR SEARCH ===" << endl;

    // Clock for time with sorting
    auto start1 = chrono::steady_clock::now();
    sort(arr, arr + n);

    // Clock for time without sorting
    auto start2 = chrono::steady_clock::now();
    long int index1 = linearSearch(arr, n, ele);
    
    auto end1 = chrono::steady_clock::now();
    auto end2 = chrono::steady_clock::now();

    if (index1 == -1) {
        cout << "The element does not exist in the array." << endl;
    } else {
        cout << "The element was found." << endl;
    }

    // Printing the elapsed times with and without sorting
    cout << "Linear search(iterative) time with sorting: " << fixed << setprecision(6) << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() / 1e6 << " milliseconds." << endl;
    cout << "Linear search(iterative) time without sorting: " << fixed << setprecision(6) << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() / 1e6 << " milliseconds." << endl;

    // Binary Search
    cout << "\n=== ITERATIVE BINARY SEARCH ===" << endl;

    // Clock for time with sorting (iterative binary search)
    auto start3 = chrono::steady_clock::now();
    sort(arr, arr + n);

	auto start4 = chrono::steady_clock::now();
    long int index2 = binarySearchIterative(arr, n, ele);
    
    auto end3 = chrono::steady_clock::now();
	auto end4 = chrono::steady_clock::now();

    if (index2 == -1) {
        cout << "The element does not exist in the array." << endl;
    } else {
        cout << "The element was found." << endl;
    }

    // Printing the elapsed times with and without sorting (iterative binary search)
    cout << "Binary search (iterative) time with sorting: " << fixed << setprecision(6) << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() / 1e6 << " milliseconds." << endl;
    cout << "Binary search (iterative) time without sorting: " << fixed << setprecision(6) << chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count() / 1e6 << " milliseconds." << endl;
    
    // Recursive Linear Search
    cout << "\n=== RECURSIVE BINARY SEARCH ===" << endl;
    
    // Clock for time with sorting (recursive binary search)
    auto start5 = chrono::steady_clock::now();
    sort(arr, arr + n);

    long int index3 = binarySearchRecursive(arr, 0, n - 1, ele);
    
    auto end5 = chrono::steady_clock::now();
    
    cout << endl;

    if (index3 == -1) {
        cout << "The element does not exist in the array." << endl;
    } else {
        cout << "The element was found." << endl;
    }

    // Printing the elapsed times with and without sorting (recursive binary search)
    cout << "Binary search (recursive) time with sorting: " << fixed << setprecision(6) << chrono::duration_cast<chrono::nanoseconds>(end5 - start5).count() / 1e6 << " milliseconds." << endl;
    
    
    delete[] arr;  // Deallocate the array

    return 0;
}