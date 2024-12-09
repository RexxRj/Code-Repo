//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int findN(int N)
    {
        if (N % 4 == 0)
            return N;
        if (N % 4 == 1)
            return 1;
        if (N % 4 == 2)
            return N + 1;
        if (N % 4 == 3)
            return 0;
    }

public:
    int findXOR(int l, int r)
    {
        // complete the function here

        return findN(r) ^ findN(l) ^ l;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;

        cout << "~" << "\n";
    }
}
// } Driver Code Ends