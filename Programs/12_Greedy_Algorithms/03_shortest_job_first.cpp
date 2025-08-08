#include <bits/stdc++.h>
using namespace std;

/*

// Shortest Job Problem

- given n processes, and each process processing time is known in units of time
- each process is arriving at time 0
- and we have to find the average waiting time
- the one with the least execution time will be executed first

SJF - Shortest Job First
- Scheduling Policy that selects the waiting process with the smallest execution time to execute next






Approach

- we need to sort it first as the shortest will go first
- keep a waiting time and a ending time
- and then we go on adding arr[i] to the ending time and before that we just add ending time to the waiting time

- Time complexity -> O(N) + O(NlogN) -> traverse + sort
- Space complexity -> O(1)




*/

int shortest_job_first(vector<int> arr)
{
    // variables
    int waiting_time = 0;
    int ending_time = 0;

    // first sort the array
    sort(arr.begin(), arr.end());

    // after that start traversing
    for (int i = 0; i < arr.size(); i++)
    {

        // first calculate the waiting time
        waiting_time += ending_time;
        ending_time += arr[i];
    }

    return (waiting_time / 5);
}

int main()
{

    vector<int> arr = {4, 3, 7, 1, 2};
    cout << "The average waiting time is " << shortest_job_first(arr);

    return 0;
}