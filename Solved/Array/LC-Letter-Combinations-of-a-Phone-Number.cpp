class Solution
{

    void solve(int ind, string &digits, vector<vector<char>> &nums, string res, vector<string> &ans)
    {
        if (ind == digits.size())
        {
            if (res != "")
                ans.push_back(res);
            return;
        }

        int digit = digits[ind] - '0';

        for (int i = 0; i < nums[digit].size(); i++)
        {
            char c = nums[digit][i];

            solve(ind + 1, digits, nums, res + c, ans);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<vector<char>> nums(10, vector<char>());

        for (int i = 2; i <= 7; i++)
        {
            int j = (i - 2) * 3;
            char a = 'a' + j;
            char b = 'a' + j + 1;
            char c = 'a' + j + 2;

            nums[i].push_back(a);
            nums[i].push_back(b);
            nums[i].push_back(c);

            if (i == 7)
            {
                char d = 'a' + j + 3;
                nums[i].push_back(d);
            }
        }

        for (int i = 1; i <= 3; i++)
        {
            char a = 'a' + 18 + i;
            nums[8].push_back(a);
        }

        for (int i = 1; i <= 4; i++)
        {
            char a = 'a' + 21 + i;
            nums[9].push_back(a);
        }

        vector<string> ans;
        string res = "";

        solve(0, digits, nums, res, ans);

        return ans;
    }
};