int Solution::solve(string A)
{

    string str = A;
    int m = A.size();

    for (int i = m - 1; i >= 0; i--)
        str += A[i];

    int n = str.size();

    vector<int> v(n, 0);

    int len = 0, i = 1;

    while (i < n)
    {
        if (str[i] == str[len])
        {
            v[i] = ++len;
            i++;
        }
        else if (len == 0)
        {
            i++;
        }
        else
        {
            len = v[len - 1];
        }
    }

    if (v[n - 1] > m)
        return 0;

    return m - v[n - 1];
}
