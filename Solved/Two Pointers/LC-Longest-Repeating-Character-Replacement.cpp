class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        vector<int> letters(27, 0);

        int left = 0, right = 0, maxLen = 0, maxFreq = 0;

        while (right < s.size())
        {
            letters[s[right] - 'A']++;

            maxFreq = max(maxFreq, letters[s[right] - 'A']);

            if (right - left + 1 - maxFreq > k)
            {
                letters[s[left] - 'A']--;
                left++;
            }

            if (right - left + 1 - maxFreq <= k)
            {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }

        return maxLen;
    }
};