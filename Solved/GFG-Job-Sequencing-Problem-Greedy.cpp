//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here

        sort(arr, arr + n, [](Job a, Job b)
             { return a.profit > b.profit; });

        int maxD = 0;

        for (int i = 0; i < n; i++)
            maxD = max(maxD, arr[i].dead);

        vector<int> jobs(maxD, -1);

        int cnt = 0, maxP = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead - 1; j >= 0; j--)
            {
                if (jobs[j] == -1)
                {
                    maxP += arr[i].profit;
                    cnt++;
                    jobs[j] = arr[i].id;
                    break;
                }
            }
        }

        return {cnt, maxP};
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends