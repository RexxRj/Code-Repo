class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        unordered_map<char, int> m;

        int len = 0, j = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                j = max(j, m[s[i]] + 1);
            }

            m[s[i]] = i;

            len = max(len, i - j + 1);
        }

        return len;
    }
};