class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int cnt = 0;
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push('(');
            else if (!st.empty())
                st.pop();
            else
                cnt++;
        }

        while (!st.empty())
        {
            cnt++;
            st.pop();
        }

        return cnt;
    }
};