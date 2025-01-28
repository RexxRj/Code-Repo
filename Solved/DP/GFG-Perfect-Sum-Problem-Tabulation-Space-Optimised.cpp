//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        // code here

        vector<int> prev(target + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= arr.size(); i++)
        {
            vector<int> cur(target + 1, 0);
            cur[0] = 1;
            for (int j = 0; j <= target; j++)
            {
                int ntake = prev[j];
                int take = 0;

                if (arr[i - 1] <= j)
                    take = prev[j - arr[i - 1]];

                cur[j] = take + ntake;
            }

            prev = cur;
        }

        return prev[target];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--)
    {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value)
        {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends