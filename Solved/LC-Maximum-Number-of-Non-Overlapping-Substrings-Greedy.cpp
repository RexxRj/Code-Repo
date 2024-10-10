class Solution
{

    int checkString(string &s, int index, vector<int> &beg, vector<int> &end)
    {
        int right = end[s[index] - 'a'];
        for (int i = index; i <= right; i++)
        {
            if (index > beg[s[i] - 'a'])
                return -1;

            right = max(right, end[s[i] - 'a']);
        }

        return right;
    }

public:
    vector<string> maxNumOfSubstrings(string s)
    {

        vector<int> beg(26, -1), end(26, -1);

        for (int i = 0; i < s.length(); i++)
        {
            if (beg[s[i] - 'a'] == -1)
                beg[s[i] - 'a'] = i;
            end[s[i] - 'a'] = i;
        }

        int prevRight = -1;
        vector<string> ans;

        for (int i = 0; i < s.length(); i++)
        {
            if (i == beg[s[i] - 'a'])
            {
                int newRight = checkString(s, i, beg, end);
                if (newRight != -1)
                {
                    if (i > prevRight)
                        ans.push_back("");

                    ans.back() = s.substr(i, newRight - i + 1);
                    prevRight = newRight;
                }
            }
        }

        return ans;
    }
};