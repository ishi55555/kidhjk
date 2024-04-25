#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    string name;
    int start_time;
    int finish_time;
};

bool sortByFinishTime(const Activity &a, const Activity &b)
{
    return a.finish_time < b.finish_time;
}

void activitySelection(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), sortByFinishTime);

    vector<string> ans;
    ans.push_back(activities[0].name);
    int last_finish_time = activities[0].finish_time;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].start_time >= last_finish_time)
        {
            ans.push_back(activities[i].name);
            last_finish_time = activities[i].finish_time;
        }
    }

    cout << "Selected activities: ";
    for (auto name : ans)
    {
        cout << name << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    for (int i = 0; i < n; i++)
    {
        cout << endl;

        cout << "Enter name of activity " << i + 1 << ": ";
        cin >> activities[i].name;

        cout << "Enter start time of activity " << i + 1 << ": ";
        cin >> activities[i].start_time;

        cout << "Enter finish time of activity " << i + 1 << ": ";
        cin >> activities[i].finish_time;
    }

    cout << "Activities are:" << endl;
    for (auto act : activities)
    {
        cout << act.name << " (" << act.start_time << ", " << act.finish_time << ")" << endl;
    }

    activitySelection(activities);

    return 0;
}

//O(nlogn), where n is the number of activities.


//Sorting: First, the activities are sorted based on their finish times. Sorting typically takes O(nlogn), where 
//n is the number of activities.
//Iterating Through Activities: After sorting, a linear scan is performed over the sorted list of activities to select the maximum number of 
//non-overlapping activities. This linear scan takes O(n) time.