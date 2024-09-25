class Solution
{

    const int BASE = 1e6;

private:
    int rabin_karp(string source, string target)
    {
        if (source == "")
            return -1;
        if (target == "" && source == "")
            return 1;
        if (source == "")
            return 0;

        int m = target.length();

        int targetHash = 0;

        int power = 1;

        for (int i = 0; i < m - 1; i++)
            power = (power * 29) % BASE;

        for (int i = 0; i < m; i++)
            targetHash = (targetHash * 29 + target[i]) % BASE;

        int hashCode = 0;

        for (int i = 0; i < source.length(); i++)
        {
            hashCode = (hashCode * 29 + source[i]) % BASE;
            if (i < m - 1)
                continue;

            if (hashCode == targetHash)
            {
                if (source.substr(i - m + 1, m) == target)
                    return i - m + 1;
            }
            else
            {
                hashCode = (hashCode - source[i - m + 1] * power) % BASE;
                if (hashCode < 0)
                    hashCode += BASE;
            }
        }

        return -1;
    }

public:
    int repeatedStringMatch(string a, string b)
    {

        if (a == b)
            return 1;
        int count = 1;
        string source = a;
        while (source.size() < b.size())
        {
            count++;
            source += a;
        }

        if (source == b)
            return count;
        if (rabin_karp(source, b) != -1)
            return count;
        if (rabin_karp(source + a, b) != -1)
            return count + 1;
        return -1;
    }
};