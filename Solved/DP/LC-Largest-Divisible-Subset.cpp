//Sorting is important!!

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& arr) {
    
            int n = arr.size();
            vector<int> LIS(n,1), parent(n);
            int maxLIS = 1, maxInd = 0;
    
            sort(arr.begin(),arr.end());
    
            for(int i = 1; i<n; i++)
            {
                parent[i] = i;
                for(int j = 0; j<i; j++)
                {
                    //cout<<"before "<<arr[i]<<" "<<arr[j]<<endl;
                    if((arr[j]%arr[i] == 0 || arr[i]%arr[j] == 0) && LIS[i]<1+LIS[j])
                    {
                        
                        LIS[i] = 1 + LIS[j];
                        parent[i] = j;
                        
                    }
                }
    
                //cout<<i<<" "<<LIS[i]<<" "<<parent[i]<<endl;
    
                if(maxLIS<LIS[i])
                {
                    maxLIS = LIS[i];
                    maxInd = i;
                }
            }
    
            vector<int> ans;
    
            while(parent[maxInd] != maxInd)
            {
                ans.push_back(arr[maxInd]);
                maxInd = parent[maxInd];
            }
    
            ans.push_back(arr[maxInd]);
    
            reverse(ans.begin(),ans.end());
    
            return ans;
            
        }
    };