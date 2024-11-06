class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {

        int left = 0, right = 0, zeroes = 0, maxLen = 0;

        while (right < nums.size())
        {
            if (nums[right] == 0)
                zeroes++;

            if (zeroes > k)
            {
                if (nums[left] == 0)
                    zeroes--;
                left++;
            }
            if (zeroes <= k)
            {
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            }

            right++;
        }

        return maxLen;
    }
};