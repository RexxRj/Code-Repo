class Solution
{

    void solve(int ind, vector<int> arr, vector<int> &brr, long long &k, long long &minC, long long C)
    {

        if (ind == arr.size())
        {
            return;
        }
        cout << "ind: " << ind << " C: " << C << endl;
        solve(ind + 1, arr, brr, k, minC, C);

        if (ind == arr.size() - 1)
            return;

        vector<int> arr_new;

        for (int i = ind + 1; i < arr.size(); i++)
            arr_new.push_back(arr[i]);
        for (int i = 0; i <= ind; i++)
            arr_new.push_back(arr[i]);

        cout << "arr_new: ";
        long long x = k;
        for (int i = 0; i < arr_new.size(); i++)
        {
            cout << arr_new[i] << " ";
            x += abs(brr[i] - arr_new[i]);
        }

        cout << "x: " << x;

        minC = minC > x + C ? x + C : minC;
        cout << " minC: " << minC << endl;

        solve(ind + 1, arr_new, brr, k, minC, C + k);
    }

public:
    long long minCost(vector<int> &arr, vector<int> &brr, long long k)
    {

        long long minC = INT_MAX;

        long long x = 0;

        for (int i = 0; i < arr.size(); i++)
        {

            x += abs(brr[i] - arr[i]);
        }

        minC = minC > x ? x : minC;
        cout << minC << endl;

        solve(0, arr, brr, k, minC, 0);

        return minC;
    }
};