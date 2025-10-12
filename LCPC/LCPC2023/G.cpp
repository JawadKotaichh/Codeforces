#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxii = 200000;
long long ans[maxii + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (ll X = 1; X <= maxii; X++)
    {
        ll X2 = X * X;
        int count = 0;
        for (ll d = 1; d * d <= X2; d++)
        {
            if (X2 % d == 0)
            {
                ll a = d, b = X2 / d;
                if (a < b && (a + b) % 2 == 0)
                    count++;
            }
        }
        ans[X] = count;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
    return 0;
}