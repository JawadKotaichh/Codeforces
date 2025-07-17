#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string s = to_string(x);
        int mini = s[0] - '0';
        for (int i = 1; i < s.size(); i++)
        {
            int d = s[i] - '0';
            if (d < mini)
            {
                mini = d;
            }
        }
        cout << mini << endl;
    }
    return 0;
}