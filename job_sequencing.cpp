#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// A structure to represent a job
struct Job {
    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// Comparator function for sorting jobs based on profit
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Returns maximum profit from jobs and updates the sequence of jobs scheduled
void printJobScheduling(Job arr[], int n) {
    // Sort all jobs according to decreasing order of profit
    sort(arr, arr + n, comparison);

    // Find maximum deadline among all jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<int> result(maxDeadline, -1); // To store result (Sequence of jobs)

    // Iterate through all given jobs
    for (int i = 0; i < n; ++i) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; --j) {
            // Free slot found
            if (result[j] == -1) {
                result[j] = i; // Add this job to result
                break;
            }
        }
    }

    // Print the result
    for (int i = 0; i < maxDeadline; ++i) {
        if (result[i] != -1) {
            cout << arr[result[i]].id << " ";
        }
    }
}

// Driver's code
int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    Job arr[n];
    cout << "Enter job details (id, deadline, profit) for each job:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }
    cout << "Following is maximum profit sequence of jobs: \n";

    // Function call
    printJobScheduling(arr, n);
    return 0;
}

//Enter the number of jobs: 5
//Enter job details (id, deadline, profit) for each job:
//a 2 100
//b 1 19
//c 2 27
//d 1 25
//e 3 15


// O(N log N) + O(N*M). :
//O(N log N ) for sorting the jobs in decreasing order of profit. 
//O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

