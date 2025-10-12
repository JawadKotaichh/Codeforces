/*
cost[i] = cost of the i-th step on a staircase
after paying the cost I can climb one or two steps

You can start from either index 0 or index 1
dp[i][j] = min cost to reach index i such that the last step is j
dp[0][0]=dp[0][1]=cost[0]
dp[1][1]=cost[1]
dp[1][0] =cost[0]+cost[1]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = cost[0];
    dp[0][1] = cost[0];
    dp[1][0] = cost[0] + cost[1];
    dp[1][1] = cost[1];
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i];
        dp[i][1] = min(dp[i - 2][0], dp[i - 2][1]) + cost[i];
    }
    dp[n][0] = min(dp[n - 1][0], dp[n - 1][1]);
    dp[n][1] = min(dp[n - 2][0], dp[n - 2][1]);

    // for (int j = 0; j < n + 1; j++)
    // {
    //     cout << "dp[" << j << "][1]= " << dp[j][0] << endl;
    //     cout << "dp[" << j << "][0]= " << dp[j][1] << endl;
    // }
    cout << min(dp[n][0], dp[n][1]) << endl;
    return 0;
}