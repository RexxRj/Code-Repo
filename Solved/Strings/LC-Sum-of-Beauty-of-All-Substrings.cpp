class Solution
{
public:
    int beautySum(string s)
    {

        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            vector<int> arr(26, 0);

            for (int j = i; j < s.length(); j++)
            {
                arr[s[j] - 'a']++;
                int maxF = 0, minF = INT_MAX;
                // cout<<s[j]<<" ";
                for (auto &x : arr)
                {
                    if (x != 0)
                    {
                        maxF = max(maxF, x);
                        minF = min(minF, x);
                    }
                }
                // cout<<maxF<<" "<<minF<<endl;
                sum += maxF - minF;
            }
            // cout<<endl;
        }

        return sum;
    }
};