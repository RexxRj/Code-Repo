// Uses concept of largest rectangle in histogram - which in turn uses next greater element on left and right
// Time Complexity: O(n*m)

class Solution
{

    int maxArr(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        int ans = INT_MIN, h, w;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i]))
            {
                h = arr[st.top()];
                st.pop();

                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                ans = max(ans, h * w);
            }

            st.push(i);
        }

        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        int n = matrix.size(), m = matrix[0].size();
        vector<int> dp(m, 0);

        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == '1')
                dp[i] = 1;
        }

        int ans = maxArr(dp);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    dp[j]++;
                else
                    dp[j] = 0;
            }

            ans = max(ans, maxArr(dp));
        }

        return ans;
    }
};