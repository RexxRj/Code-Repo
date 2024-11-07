class Solution
{
public:
    int numberOfSubstrings(string s)
    {

        int left = 0, right = 0, sumAll = 0, sum2 = 0;
        unordered_map<char, int> m;

        while (right < s.size())
        {
            m[s[right]]++;

            while (m.size() > 2)
            {
                m[s[left]]--;
                if (m[s[left]] == 0)
                    m.erase(s[left]);
                left++;
            }

            sumAll += right + 1;
            sum2 += right - left + 1;
            right++;
        }

        return sumAll - sum2;
    }
};