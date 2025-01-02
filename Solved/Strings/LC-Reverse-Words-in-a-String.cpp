class Solution
{
public:
    string reverseWords(string s)
    {

        string ans = "", word = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                word += s[i];
            }
            else if (word != "")
            {
                if (ans != "")
                    ans = word + " " + ans;
                else
                    ans = word;

                word = "";
            }
        }

        if (word != "")
        {
            if (ans != "")
                ans = word + " " + ans;
            else
                ans = word;
        }

        return ans;
    }
};