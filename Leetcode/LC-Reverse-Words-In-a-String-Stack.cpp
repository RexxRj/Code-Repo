class Solution
{
public:
    string reverseWords(string s)
    {

        stack<char> st;

        string revs = "";

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && st.empty())
                continue;

            if (s[i] != ' ')
                st.push(s[i]);
            else
            {
                while (!st.empty())
                {
                    revs += st.top();
                    st.pop();
                }
                revs += " ";
            }
        }

        if (st.empty())
        {
            revs.pop_back();
            return revs;
        }

        while (!st.empty())
        {
            revs += st.top();
            st.pop();
        }

        return revs;
    }
};