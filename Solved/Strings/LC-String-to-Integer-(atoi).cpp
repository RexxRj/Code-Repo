class Solution
{
public:
    int myAtoi(string s)
    {

        long ans = 0;

        int i = 0;

        while (i < s.length() && s[i] == ' ')
            i++;

        bool nsign = false;

        if (s[i] == '-' || s[i] == '+')
        {
            if (s[i] == '-')
                nsign = true;
            i++;
        }

        while (i < s.length() && s[i] == '0')
            i++;

        long x = 10;
        while (i < s.length() && int(s[i] - '0') >= 0 && int(s[i] - '0') <= 9)
        {
            ans = x * ans + int(s[i] - '0');
            if (ans > INT_MAX)
            {
                if (nsign)
                    return INT_MIN;
                return INT_MAX;
            }
            i++;
        }
        if (nsign)
            return int(-ans);
        return int(ans);
    }
};
