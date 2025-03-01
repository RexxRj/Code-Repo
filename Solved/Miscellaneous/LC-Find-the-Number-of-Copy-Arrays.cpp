class Solution
{

    int solve(int i, int minL, int maxL, vector<int> &original, vector<vector<int>> &bounds)
    {
        if (i == original.size())
            return maxL >= minL ? maxL - minL + 1 : 0;

        if (i == 0)
            return solve(i + 1, bounds[i][0], bounds[i][1], original, bounds);

        int num = original[i] - original[i - 1];

        minL = max(minL + num, bounds[i][0]);
        maxL = min(maxL + num, bounds[i][1]);

        return solve(i + 1, minL, maxL, original, bounds);
    }

public:
    int countArrays(vector<int> &original, vector<vector<int>> &bounds)
    {

        return solve(0, 0, 0, original, bounds);
    }
};