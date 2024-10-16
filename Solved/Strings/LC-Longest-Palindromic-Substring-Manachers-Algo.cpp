class Solution
{
public:
    string longestPalindrome(string s)
    {

        string str = "#";

        for (int i = 0; i < s.length(); i++)
            str = str + s[i] + "#";

        vector<int> v(str.length(), 0);

        int center = 0, right = 0;
        int maxlen = 0, maxcenter = 0;

        for (int i = 0; i < str.length(); i++)
        {

            int mirror = 2 * center - i;

            if (right > i)
                v[i] = min(v[mirror], right - i);

            int a = i + (v[i] + 1);
            int b = i - (v[i] + 1);

            while (b >= 0 && a < str.length() && str[a] == str[b])
            {

                b--;
                a++;
                v[i]++;
            }

            if (v[i] > maxlen)
            {
                maxlen = v[i];
                maxcenter = i;
            }

            if (i + v[i] > right)
            {

                right = i + v[i];
                center = i;
            }
        }

        return s.substr((maxcenter - maxlen) / 2, maxlen);
    }
};