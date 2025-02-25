//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        // code here
        vector<int> lisFront(n, 1), lisBack(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    lisFront[i] = max(lisFront[i], 1 + lisFront[j]);

                if (nums[n - 1 - i] > nums[n - 1 - j])
                    lisBack[n - 1 - i] = max(lisBack[n - 1 - i], 1 + lisBack[n - 1 - j]);
            }
        }

        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            if (lisFront[i] != 1 && lisBack[i] != 1)
                maxLen = max(maxLen, lisFront[i] + lisBack[i] - 1);
        }

        return maxLen;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends