class Solution
{

    long long calc(long long num, long long power, long long mod)
    {
        if (power == 0)
            return 1;

        if (power % 2 == 0)
            return calc((num * num) % mod, power / 2, mod);

        return (num * calc((num * num) % mod, (power - 1) / 2, mod)) % mod;
    }

public:
    int countGoodNumbers(long long n)
    {

        long long evenP = ceil((double)n / 2);
        long long oddP = floor(n / 2);
        long long mod = 1000000007;

        long long evenAns = calc(5, evenP, mod);
        long long oddAns = calc(4, oddP, mod);

        return (evenAns * oddAns) % mod;
    }
};
// 806166225460393