/*
dp[i][buy] = max_profit got till index i if I buy stock at i
dp[i][sell] = max_profit got till index i if I sell stock at i

dp[0][buy] = -prices[0]
dp[0][sell] = 0

dp[1][buy] = max(dp[0][buy],-prices[1] + dp[0][sell])
dp[1][sell] = max(dp[0][sell],dp[0][buy] + prices[1])

dp[i][buy] = max(dp[i-1][buy],dp[i-1][sell] -prices[i])
dp[i][sell] = max(dp[i-1][sell],dp[i-1][buy] +prices[i])

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    // cout << dp[n - 1][0] << endl;
    cout << dp[n - 1][1] << endl;
    return 0;
}