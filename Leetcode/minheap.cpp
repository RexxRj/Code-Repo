#include <iostream>
#include<vector>
#include<sstream> 

using namespace std;

void heapify(vector<int>& heap, int x)
{
    int n = heap.size();
    heap.push_back(x);
    if(n == 1) return;

    int parent = n/2;
    //cout<<"parent "<<parent<<" n "<<n<<" heap[parent] heap[n]"<<heap[parent]<<" "<<heap[n]<<endl;
    while(parent>0 && heap[parent] > heap[n] )
    {
       // cout<<"swap"<<endl;
        swap(heap[parent],heap[n]);
        n = parent;
        parent = n/2;
    }

    return;
    

}


int remove(vector<int>& heap)
{
    int n = heap.size();
    if(n == 1) return 0;

    int res = heap[1];
    swap(heap[1],heap[n-1]);
    heap.pop_back();
    int i = 1;

    while(i<n)
    {
        int smallest = i;
        int l = 2*i;
        int r = 2*i +1;
        if(heap[i]>heap[l])
        smallest = l;
        if(heap[i]>heap[r])
        smallest = r;

        if(i == smallest) break;

        swap(heap[i],heap[smallest]);
        i = smallest;
    }

    return res;
}


vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.

    vector<int> heap(1,-1);
    vector<int> ans;

    for(int i = 0; i<q.size(); i++)
    {
        if(q[i].size() == 2)
        {
           //cout<<"heapify: "<<q[i][1]<<endl;
            heapify(heap,q[i][1]);
        }
        else if(q[i].size() == 1)
        {
           // cout<<"remove "<<q[i][0]<<endl;
            ans.push_back(remove(heap));
        }
       // cout<<"heap: "<<endl;
        //for(auto &x: heap)
        //cout<<x<<" ";
       // cout<<endl;
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;
    vector<vector<int>> ans;
    while(t--)
    {
       // cout<<"begining "<<t<<endl;
        int N;
        cin>>N;
        int n = N;
        vector<vector<int>> q;
        cin.ignore();
        while(N--)
        {
            string line;
            getline(cin,line);

            istringstream iss(line);
            vector<int> cur;
            int num;

            while(iss>>num)
            cur.push_back(num);

            q.push_back(cur);
           // cout<<"N "<<N<<endl;
            
        }

       // cout<<"end "<<t<<endl;

        ans.push_back(minHeap(n,q));

        

    }

    for(auto& x: ans)
    {
        for(auto&y: x)
        cout<<y<<" ";
        cout<<endl;
    }

    return 0;
}