class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        if (dividend == divisor)
            return 1;

        bool sign = true;

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = false;

        long n = abs(dividend), d = abs(divisor);

        int q = 0;

        while (n >= d)
        {
            int cnt = 0;

            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }
            q += (1 << cnt);
            n -= (d << cnt);
        }

        if (q == (1 << 31))
            return sign ? INT_MAX : INT_MIN;

        return sign ? q : (-1 * q);
    }
};