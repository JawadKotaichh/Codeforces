/*
....
.*..
...*
*...




dp[i][j] = number of ways I can get to pos (i,j)
dp[i][j] =(dp[i-1][j] + dp[i][j-1])(if a[i][j] is available)
answer : dp[n-1][n-1]
base case: dp[0][0] = 1 (if available)
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long MOD = 1e9 + 7;
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    // cout << "hi" << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (a[0][0] != '*')
    {
        dp[0][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != '*')
            {
                if (j - 1 >= 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
                if (i - 1 >= 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n - 1][n - 1];
}