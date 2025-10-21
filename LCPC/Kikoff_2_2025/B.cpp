#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int P, Q;
        cin >> P >> Q;
        vector<int> v(Q);
        for (int i = 0; i < Q; i++)
        {
            cin >> v[i];
        }
        v.push_back(0);
        v.push_back(P + 1);
        sort(v.begin(), v.end());
        vector<vector<int>> dp(Q + 2, vector<int>(Q + 2, 0));

        for (int len = 2; len < Q + 2; ++len)
        {
            for (int i = 0; i + len < Q + 2; ++i)
            {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], v[j] - v[i] - 2 + dp[i][k] + dp[k][j]);
                }
                if (dp[i][j] == INT_MAX)
                    dp[i][j] = 0;
            }
        }
        cout << dp[0][Q + 1] << endl;
    }
    return 0;
}