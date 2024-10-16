#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {

        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {

        if (parent[node] == node)
            return node;
        else
            return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {

        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if (ult_u == ult_v)
            return;
        else if (rank[ult_u] < rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else if (rank[ult_v] < rank[ult_u])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }

    void unionBySize(int u, int v)
    {

        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if (ult_u == ult_v)
            return;
        if (size[ult_u] < size[ult_v])
        {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else
        {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

int main()
{
    DisjointSet ds1(5), ds2(5);

    cout << "Union by Rank\n";
    ds1.unionByRank(1, 2);
    ds1.unionByRank(3, 4);
    ds1.unionByRank(4, 5);
    cout << "Checking 1 and 3\n";
    if (ds1.findUPar(1) == ds1.findUPar(3))
        cout << "Same\n";
    else
        cout << "Not Same\n";
    ds1.unionByRank(2, 3);
    cout << "Checking 1 and 3 again\n";
    if (ds1.findUPar(1) == ds1.findUPar(3))
        cout << "Same\n";
    else
        cout << "Not Same\n";

    cout << "Union by Size\n";
    ds2.unionBySize(1, 2);
    ds2.unionBySize(3, 4);
    ds2.unionBySize(4, 5);
    cout << "Checking 1 and 3\n";
    if (ds2.findUPar(1) == ds2.findUPar(3))
        cout << "Same\n";
    else
        cout << "Not Same\n";
    ds2.unionBySize(2, 3);
    cout << "Checking 1 and 3 again\n";
    if (ds2.findUPar(1) == ds2.findUPar(3))
        cout << "Same\n";
    else
        cout << "Not Same\n";
}