//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int total = accumulate(arr.begin(), arr.end(), 0);
        double sum1 = (double)(total + d) / 2;
        int target = sum1;

        if (target != sum1)
            return 0;

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

                cur[j] = ntake + take;
            }

            prev = cur;
        }

        return prev[target];
    }

    /*sum1 - d = sum2;

   total = sum1 + sum1 - d;

   total + d / 2 = sum1;*/
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends