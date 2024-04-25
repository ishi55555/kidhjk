#include <iostream>
#include <algorithm>

using namespace std;

int findNoCabs(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    
    int i = 1, j = 0;
    int result = 1;
    int cabsNeeded = 1;
    

    while (i < n && j < n) {

        if (arr[i] > dep[j]) {
            cabsNeeded--;
            j++;
        } 
        else if (arr[i] <= dep[j]) {
            cabsNeeded++;
            i++;
        }
        
        if (cabsNeeded > result) {
            result = cabsNeeded;
        }
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    
    int arr[n], dep[n];
    
    cout << "Enter the arrival times:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << "Enter the departure times:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> dep[i];
    }
    
    int minCabs = findNoCabs(arr, dep, n);
    cout << "Minimum number of cabs required: " << minCabs << endl;
    
    return 0;
}

//Enter the number of persons: 5
//Enter the arrival times:
//1 2 3 5 7
//Enter the departure times:
//3 4 6 8 9


