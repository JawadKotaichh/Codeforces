#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t != 0)
    {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> v(n);
        vector<int> pos(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if (k >= x + 1)
        {
            for (ll i = 0; i <= x; i++)
                cout << i << (i == x ? '\n' : ' ');
            continue;
        }
        vector<pair<ll, ll>> gaps;
        for (int i = 0; i + 1 < n; i++)
        {
            ll len = v[i + 1] - v[i];
            ll mid = (v[i + 1] + v[i]) / 2;
            gaps.push_back({len, mid});
        }
        if (v[0] > 0)
            gaps.push_back({v[0], 0});
        if (v.back() < x)
            gaps.push_back({x - v.back(), x});
        sort(gaps.begin(), gaps.end(), [&](auto &p1, auto &p2)
             { return p1.first > p2.first; });
        vector<ll> teleports;
        for (auto &g : gaps)
        {
            if ((int)teleports.size() == k)
                break;
            ll pos = g.second;
            if (pos < 0)
                pos = 0;
            if (pos > x)
                pos = x;
            teleports.push_back(pos);
        }
        sort(teleports.begin(), teleports.end());
        teleports.erase(unique(teleports.begin(), teleports.end()), teleports.end());

        for (ll i = 0; (int)teleports.size() < k && i <= x; i++)
        {
            if (!binary_search(teleports.begin(), teleports.end(), i))
                teleports.push_back(i);
        }

        for (int i = 0; i < k; i++)
            cout << teleports[i] << (i + 1 == k ? '\n' : ' ');
        t -= 1;
    }

    return 0;
}