class Solution
{
private:
    string expand(int i, int j, string &s)
    {
        int left = i, right = j;

        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

public:
    string longestPalindrome(string s)
    {

        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            string odd = expand(i, i, s);
            if (odd.length() > ans.length())
                ans = odd;

            string even = expand(i, i + 1, s);
            if (even.length() > ans.length())
                ans = even;
        }

        return ans;
    }
};