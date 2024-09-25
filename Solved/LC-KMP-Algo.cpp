class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        int m = haystack.length(), n = needle.length();

        vector<int> lps(n, 0);

        int i = 1, len = 0;

        while (i < n)
        {
            if (needle[len] == needle[i])
            {
                lps[i] = ++len;
                i++;
            }
            else if (len == 0)
            {
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }

        i = 0;
        int j = 0;

        while (i < m)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }

            if (j == needle.size())
            {
                return i - n;
            }
        }

        return -1;
    }
};