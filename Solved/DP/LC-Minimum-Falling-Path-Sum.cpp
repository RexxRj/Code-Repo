class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int ans = matrix[0][0];

        for (int i = 1; i < matrix.size(); i++)
        {
            int res = INT_MAX;

            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (j == 0)
                {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                }
                else if (j == matrix[i].size() - 1)
                {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                }
                else
                {
                    matrix[i][j] += min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i - 1][j + 1]));
                }

                res = min(res, matrix[i][j]);
            }

            ans = res;
        }

        return ans;
    }
};