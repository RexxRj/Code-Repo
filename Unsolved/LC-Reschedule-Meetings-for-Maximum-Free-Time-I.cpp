class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {

        int prevT = 0, free = 0, maxFree = free;

        int i = 0, j = 0;

        while (j < endTime.size())
        {
            if (k)
            {
                if (prevT != startTime[j])
                {
                    free += startTime[j] - prevT;
                    prevT = endTime[j];
                    k--;
                }
                else
                {
                    prevT = endTime[j];
                }
            }
            else
            {
                free += startTime[j] - prevT;
                maxFree = max(maxFree, free);

                if (i == 0)
                    free -= startTime[0] - 0;
                i++;
                free -= startTime[i] - endTime[i - 1];
            }
            j++;
        }

        free += eventTime - endTime[j - 1];
        maxFree = max(maxFree, free);

        return maxFree;
    }
};