class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        vector<int> nse(heights.size(),heights.size()-1),pse(heights.size(),0);

        stack<int> st;

        for(int i = 0 ; i<heights.size(); i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();

            if(!st.empty()) pse[i] = st.top()+1;

            st.push(i);
        }

        st = stack<int>();

        for(int i = heights.size()-1; i>=0 ; i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();

            if(!st.empty()) nse[i] = st.top()-1;

            st.push(i);
        }
        

        int maxArr = 0;

        for(int i = 0; i<heights.size();i++)
        {
            cout<<nse[i]<<" "<<pse[i]<<endl;
            maxArr = max(maxArr,(nse[i]-pse[i]+1)*heights[i]);
        }

        

        return maxArr;
        
    }
};