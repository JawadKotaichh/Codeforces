#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    if (!(cin >> n >> t))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    const int INF = 1e9;
    vector<int> dp(t + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= t; ++i)
    {
        for (int c : a)
        {
            if (i >= c && dp[i - c] != INF)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    cout << (dp[t] == INF ? -1 : dp[t]) << '\n';
    return 0;
}
