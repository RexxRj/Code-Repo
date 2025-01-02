//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lenOfLongestSubarr(vector<int> &arr, int k)
    {
        // code here

        unordered_map<int, int> m;
        int len = 0, sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            int x = sum - k;

            if (sum == k)
            {
                len = i + 1;
            }
            else if (m.find(x) != m.end())
            {
                len = max(len, i - m[x]);
            }

            if (m.find(sum) == m.end())
                m[sum] = i;
        }

        return len;
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
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value)
        {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends