//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int totalFruits(vector<int> &arr)
    {

        int left = 0, right = 0, maxLen = 0;
        unordered_map<int, int> m;

        while (right < arr.size())
        {
            m[arr[right]]++;

            if (m.size() > 2)
            {
                m[arr[left]]--;
                if (m[arr[left]] == 0)
                    m.erase(arr[left]);
                left++;
            }
            if (m.size() <= 2)
                maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--)
    {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num)
        {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends