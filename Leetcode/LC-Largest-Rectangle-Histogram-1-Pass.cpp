class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArr = 0;
        int pse;
        int n = heights.size();

        for(int i = 0 ; i<=n; i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int index = st.top();
                st.pop();

                if(!st.empty())
                pse = st.top()+1;
                else
                pse = 0;

                maxArr = max(maxArr,(i-pse)*heights[index]);
            }
            st.push(i);
            
        }
        return maxArr;
        
    }
};