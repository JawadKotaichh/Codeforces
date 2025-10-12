/*
    n=2
    dp[i][mawsoul] = height i and e5er wehde mawsoule
    dp[i][mafsoul] = height i and e5er wehde mfsoule

    dp[i][mawsoul] = 2*dp[i-1][mawsoule] + dp[i-1][mafsoule]
    dp[i][mafsoul]=dp[i-1][mawsoule]+4*dp[i-1][mafsoule]


    dp[1][mawsoul] = 1
    dp[1][mafsoul]= 1

    dp[2][mawsoul] = 2+1=3
    dp[2][mafsoule] = 1+4*1=5

    0->mawsoul
    1->mafsoul

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 1e9 + 7;
    int t;
    cin >> t;

    vector<int> queries(t);
    int maxn = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> queries[i];
        maxn = max(maxn, queries[i]);
    }

    vector<vector<long long>> dp(maxn + 1, vector<long long>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD;
    }

    for (int n : queries)
    {
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
}
