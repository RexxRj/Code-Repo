//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> LIS(n, 1);
        int maxLIS = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
            }

            maxLIS = max(maxLIS, LIS[i]);
        }

        return maxLIS;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--)
    {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends