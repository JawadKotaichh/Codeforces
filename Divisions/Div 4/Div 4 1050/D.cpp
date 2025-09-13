#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*

    lawnmower  initialy turned off
    n fields
    i-th field as a[i] dandelions
    odd nbr of dandelions -> lawnmower change state
    if lawnmower = 1:
        cut all dandelions
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        ll max_nb_of_dandelions = 0;
        vector<ll> odd;
        vector<ll> even;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % 2 == 0)
            {
                even.push_back(a[j]);
            }
            else
            {
                odd.push_back(a[j]);
            }
        }
        sort(odd.begin(), odd.end());
        if (odd.size() != 0)
        {
            max_nb_of_dandelions += accumulate(even.begin(), even.end(), 0LL);
            max_nb_of_dandelions += odd.back();
            int o_i = 0;
            int odd_e = odd.size() - 2;
            while (o_i < odd_e)
            {
                max_nb_of_dandelions += odd[odd_e];
                odd_e -= 1;
                o_i += 1;
            }
            cout << max_nb_of_dandelions << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}