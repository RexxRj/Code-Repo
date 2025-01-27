// This problem cannot be solved using DP, meet in the middle approach is used here.

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {

        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);

        int N = n / 2;

        vector<vector<int>> left(N + 1), right(N + 1);

        for (int i = 0; i < (1 << N); i++)
        {
            int ind = i, j = 0, sz = 0, l = 0, r = 0; // get all subsets for left and right

            while (ind)
            {
                if (ind & 1)
                {
                    sz++;
                    l += nums[j];
                    r += nums[j + N];
                }
                j++;
                ind = ind >> 1;
            }

            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for (int sz = 0; sz <= N; sz++)
            sort(right[sz].begin(), right[sz].end());

        res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        for (int sz = 1; sz < N; sz++)
        {
            for (auto &a : left[sz])
            {
                int b = (sum - 2 * a) / 2, rsz = N - sz; // find b. total - 2(a+b) = 0, calc b from here
                auto &v = right[rsz];

                auto itr = lower_bound(v.begin(), v.end(), b);

                if (itr != v.end())
                    res = min(res, abs(sum - 2 * (a + (*itr)))); // check for greater than equal

                // not required, since a+b | a2 + b2, a2 will also come anyways
                /*if(itr!=v.begin()){
                    auto it = itr;
                    --it;
                    res = min(res,abs(sum - 2*(a+(*it)))); //check for less than equal
                }*/
            }
        }

        return res;
    }
};