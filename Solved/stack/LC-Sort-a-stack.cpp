//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);

        cout << "~" << "\n";
    }
}
// } Driver Code Ends

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort()
{
    // Your code here

    if (s.size() == 0)
        return;

    int n = s.top();

    stack<int> s2;

    while (!s.empty())
    {
        int x = s.top();
        s.pop();

        if (x > n)
            n = x;

        s2.push(x);
    }

    while (!s2.empty())
    {
        int x = s2.top();
        s2.pop();

        if (x != n)
            s.push(x);
        else
            break;
    }

    while (!s2.empty())
    {
        int x = s2.top();
        s2.pop();

        s.push(x);
    }

    sort();

    s.push(n);
}