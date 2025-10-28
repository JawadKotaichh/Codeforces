#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    if (!(cin >> n >> m))
        return 0;

    vector<long long> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    sort(p.begin(), p.end());

    int bought = 0;
    for (long long price : p)
    {
        if (m >= 10LL * price)
        {
            m -= price;
            ++bought;
        }
        else
        {
            break;
        }
    }
    cout << bought << '\n';
    return 0;
}
