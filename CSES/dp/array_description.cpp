/*
    dp[i][curr] = the total number of ways satisfying array description
    0->i where curr is what I put on index i
    if A[i-1]==0 and A[i]==0:
        dp[i][curr] = dp[i-1][curr] + dp[i-1][curr-1]+dp[i-1][curr+1]
    else if A[i-1]!=0 and A[i]==0:
        if A[i-1]=1<=curr<=A[i-1]+1:
            dp[i][curr] = dp[i-1][A[i-1]]
    else if A[i-1]==0 and A[i]!=0:
        if curr ==A[i]:
            dp[i][curr] = dp[i-1][A[i]-1]+dp[i-1][A[i]]+dp[i-1][A[i]+1]
    else:
        if curr==A[i]:
            dp[i][curr] = dp[i-1][A[i-1]]
    answer is sum(dp[n-1][1...m])
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    int m;
    cin >> n >> m;
    long long MOD = 1e9 + 7;
    vector<long long> A(n);
    for (int j = 0; j < n; j++)
    {
        cin >> A[j];
    }
    bool already_off = false;
    for (int j = 1; j < n; j++)
    {
        if (A[j] != 0 && A[j - 1] != 0)
        {
            if (abs(A[j] - A[j - 1]) > 1)
            {
                already_off = true;
                break;
            }
        }
    }
    if (already_off)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));
        if (A[0] != 0)
        {

            dp[0][A[0]] = 1;
        }
        else
        {

            for (int curr = 1; curr <= m; curr++)
            {
                dp[0][curr] = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int curr = 1; curr <= m; curr++)
            {
                if (A[i - 1] == 0 && A[i] == 0)
                {
                    long long v = dp[i - 1][curr] % MOD;
                    if (curr > 1)
                        v = (v + dp[i - 1][curr - 1]) % MOD;
                    if (curr < m)
                        v = (v + dp[i - 1][curr + 1]) % MOD;
                    dp[i][curr] = v;
                }

                else if (A[i - 1] != 0 and A[i] == 0)
                {
                    if (A[i - 1] - 1 <= curr && curr <= A[i - 1] + 1)
                    {

                        dp[i][curr] = (dp[i - 1][A[i - 1]]) % MOD;
                    }
                }
                else if (A[i - 1] == 0 && A[i] != 0)
                {
                    if (curr == A[i])
                    {
                        dp[i][curr] = (dp[i - 1][A[i]]) % MOD;
                        if (A[i] < m)
                        {
                            dp[i][curr] += (dp[i - 1][A[i] + 1]) % MOD;
                        }
                        if (A[i] > 0)
                        {
                            dp[i][curr] += (dp[i - 1][A[i] - 1]) % MOD;
                        }
                    }
                }
                else
                {
                    if (curr == A[i])
                    {
                        dp[i][curr] = (dp[i - 1][A[i - 1]]) % MOD;
                    }
                }
            }
        }
        long long sumi = 0;
        for (int curr = 1; curr <= m; curr++)
        {
            sumi = (sumi + dp[n - 1][curr]) % MOD;
        }
        cout << sumi << endl;
    }
}