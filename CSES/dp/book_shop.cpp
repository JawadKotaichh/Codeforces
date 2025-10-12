#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> BC(n);
    vector<int> BP(n);
    for (int i = 0; i < n; i++)
        cin >> BC[i];
    for (int i = 0; i < n; i++)
        cin >> BP[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= x; k++)
        {
            dp[i][k] = dp[i - 1][k];
            if (k - BC[i - 1] >= 0)
            {
                dp[i][k] = max(dp[i - 1][k - BC[i - 1]] + BP[i - 1], dp[i][k]);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}