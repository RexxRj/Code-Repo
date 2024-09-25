#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkcows(vector<int>& arr, int& dist, int cows)
{
    int cord = 0;
    cows--;

    for(int i = 1; i<arr.size(); i++)
    {
        if(arr[i] - arr[cord]>=dist)
        {
            cord = i;
            cows--;
        }
        if(cows == 0)
        return true;
    }
    return false;
}

int maxmindist(vector<int>& arr,int& cows)
{

    sort(arr.begin(),arr.end());

    int mx = *max_element(arr.begin(),arr.end());
    int mn = *min_element(arr.begin(),arr.end());

    int low = 1, high = mx-mn, ans = 0;

    while(low<=high)
    {
        int mid = (low+high)/2;

        if(checkcows(arr,mid,cows))
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return ans;
}

int main()
{
    int t = 0;
    cin>>t;

    while(t--)
    {
        int N = 0,C = 0;
        cin>>N>>C;
        vector<int> arr;
        int val;
        while(N--)
        {
            cin>>val;
            arr.push_back(val);
        }

        int ans = maxmindist(arr,C);
        cout<<ans<<endl;
    }

    return 0;
}