#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};

    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= i - 1; k++)
        {
            for (const string &L : dp[k])
            {
                for (const string &R : dp[i - 1 - k])
                {
                    dp[i].push_back("(" + L + ")" + R);
                }
            }
        }
        sort(dp[i].begin(), dp[i].end());
        dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());
    }

    for (auto &s : dp[n])
        cout << s << ", ";
    cout << endl;
    return 0;
}
