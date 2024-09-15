class Solution {
    private:
    struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b)
    {
        return a.first<b.first;
    }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        vector<int> ans;

        for(int i = 0; i<k; i++)
        pq.push(make_pair(nums[i],i));

        ans.push_back(pq.top().first);

        for(int i = k; i<nums.size(); i++)
        {
            int index = i-k+1;

            while(!pq.empty() && pq.top().second<index)
            {
                pq.pop();
            }

            pq.push(make_pair(nums[i],i));
            ans.push_back(pq.top().first);
        }

        return ans;
        
    }
};