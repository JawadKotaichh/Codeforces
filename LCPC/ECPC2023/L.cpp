#include <bits/stdc++.h>
using namespace std;
/*
    summation of P[i]-i=k for all i from 1 to n
*/
int main()
{
    int t;
    cin >> t;
    long long mod = 1e9 + 7;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<char> used(n + 1, 0);
        vector<int> P(n + 1);
        iota(P.begin(), P.end(), 0);
        long long need = k;
        if (k % 2 != 0 or k > (n * n) / 2)
        {
            cout << "No" << endl;
        }
        else
        {
            for (int i = 1; i <= n && need >= 2; ++i)
            {
                if (used[i])
                    continue;
                long long maxd = min<long long>(n - i, need / 2);
                int j = i + maxd;
                while (j > i && used[j])
                    --j;
                if (j == i)
                    continue;
                int d = j - i;
                swap(P[i], P[j]);
                used[i] = used[j] = 1;
                need -= 2LL * d;
            }
            if (need != 0)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
                for (int i = 1; i <= n; ++i)
                {
                    cout << P[i] << (i == n ? '\n' : ' ');
                }
            }
        }
        t -= 1
    }
    return 0;
}