class Solution
{
public:
    int numberOfSubstrings(string s)
    {

        int cnt = 0;
        vector<int> arr(3, -1);

        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a'] = i;

            if (arr[0] != -1 && arr[1] != -1 && arr[2] != -1)
            {
                cnt += min(arr[0], min(arr[1], arr[2])) + 1;
            }
        }

        return cnt;
    }
};