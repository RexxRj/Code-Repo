int Solution::solve(string A)
{

    int n = A.size();

    vector<int> lps(n, 0);

    int i = n - 1, len = 0;

    while (i > 0 && i >= len)
    {
        cout << i << " " << len << endl;
        if (A[len] == A[i])
        {
            lps[i] = ++len;
            i--;
        }
        else if (len == 0)
        {
            i--;
        }
        else
        {
            len = lps[len - 1];
        }

        if (i < len)
        {
            return n - (i + len + 1);
        }
    }

    return n - 1;
}

/*xyabcbazw

A A C E C A A A A
0     4 3 2 2 2 1

A B C
0 0 0

8
A B C C B A X Y Z ABC
0     3 2 1 0 0 0


0 1 2 3 4 5 6 7
a a b c b a a a
0           2 1
*/
