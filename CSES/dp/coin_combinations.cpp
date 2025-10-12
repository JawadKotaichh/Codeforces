#include <bits/stdc++.h>
using namespace std;

/*
    dp[i][x] = number of ways to have sum
    x using elements sort starting from index i
    case 1:
        take a[i] => m*a[i] while m*a[i] <=x
        // dp[i][x] = dp[i+1][x-m*a[i]] wrong complexity
        dp[i][x] = dp[i][x-a[i]]
    case 2:
        do not take it
        dp[i][x] = dp[i+1][x]

    dp[i] =
    number of ways to get the sum = i using
    any elements from the set

*/

int get_combinations_2(int n, int x, vector<int> coins)
{
    int mod = 1e9 + 7;
    vector<vector<int>> dp(coins.size() + 1, vector<int>(x + 1, 0));
    dp[coins.size()][0] = 1;
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        for (int l = 0; l <= x; l++)
        {
            if (l - coins[i] >= 0)
            {
                dp[i][l] += dp[i][l - coins[i]];
                dp[i][l] %= mod;
            }

            dp[i][l] += dp[i + 1][l];
            dp[i][l] %= mod;
        }
    }
    return dp[0][x];
}

int get_coins_combinations(int n, int x, vector<int> coins)
{
    int mod = 1e9 + 7;
    vector<int> dp(x + 1, 0);
    sort(coins.begin(), coins.end());
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0)
            {

                (dp[i] += dp[i - coins[j]]) %= mod;
            }
        }
    }
    return dp[x];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int j = 0; j < n; j++)
        cin >> coins[j];
    cout << get_combinations_2(n, x, coins) << endl;
    return 0;
}