class Solution
{
public:
    string minWindow(string s, string t)
    {

        unordered_map<char, int> m;

        for (int i = 0; i < t.size(); i++)
            m[t[i]]++;

        int left = 0, right = 0, cnt = 0, minlen = 1e9, mini = -1;

        while (right < s.length())
        {
            if (m[s[right]] > 0)
                cnt++;
            m[s[right]]--;

            while (cnt == t.size())
            {
                if (minlen > right - left + 1)
                {
                    minlen = right - left + 1;
                    mini = left;
                }
                m[s[left]]++;
                if (m[s[left]] > 0)
                    cnt--;
                left++;
            }

            right++;
        }

        if (mini == -1)
            return "";

        return s.substr(mini, minlen);
    }
};