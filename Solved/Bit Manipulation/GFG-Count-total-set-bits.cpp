//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if (n == 0)
            return 0;
        // Your logic here
        int x = 0;

        while ((1 << x) <= n)
        {
            x++;
        }
        x--;

        return x * (1 << (x - 1)) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
        // x*(1<<(x-1))  = x * pow(2,x-1);
        //(n - (1<<x) + 1) = n - pow(2,x) + 1;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer

        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends