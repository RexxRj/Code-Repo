//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    void display(vector<int> &arr)
    {
        for (auto &x : arr)
            cout << x << " ";
        cout << endl;
    }

    vector<int> findAllSubsets(int l, int r, vector<int> &arr)
    {
        int N = r - l;

        vector<int> res;

        for (int i = 0; i < (1 << N); i++)
        {
            int ind = i, j = l, sum = 0;

            while (ind)
            {
                if (ind & 1)
                {
                    sum += arr[j];
                }

                j++;
                ind = ind >> 1;
            }
            res.push_back(sum);
        }

        return res;
    }

public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int n = arr.size();

        if (n == 1)
            return 0;

        int total = accumulate(arr.begin(), arr.end(), 0);
        vector<int> left, right;

        left = findAllSubsets(0, n / 2, arr);
        right = findAllSubsets(n / 2, n, arr);

        // display(left);

        int ans = 0;

        sort(right.begin(), right.end());

        // display(right);

        for (int i = 0; i < left.size(); i++)
        {
            int sum1 = left[i];
            double sum2 = (double)(total + d - 2 * sum1) / 2;

            auto itr = lower_bound(right.begin(), right.end(), sum2);

            while (itr != right.end() && (*itr) == sum2)
            {
                // cout<<sum1<<" & "<<sum2<<endl;
                ++ans;
                ++itr;
            }
        }

        return ans;
    }

    /*sum1 - d = sum2;

    total = sum1 + sum1 - d;

    total + d / 2 = sum1;*/

    /* a+b - (total - (a+b)) = d

     a + b - total + a + b = d

     2b = total + d - 2a
     b = (total + d - 2a)/2*/
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