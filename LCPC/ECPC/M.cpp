#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        vector<ll> cum_sum;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cum_sum.push_back(arr[0]);
        for (int i = 1; i < n; i++)
            cum_sum.push_back(arr[i] + cum_sum[i - 1]);

        for (int k = 0; k < cum_sum.size(); k++)
        {
            cout << cum_sum[k] << ", ";
        }
        cout << endl;
        ll cost = 0;
        for (int i = 0; i < n; i++)
        {
            ll s1 = cum_sum[i];
            ll s2 = cum_sum[n - 1] - cum_sum[i];
            cost = cost ^ s1;
            cost = cost ^ s2;
        }
        cout << cost << endl;
    }
    return 0;
}