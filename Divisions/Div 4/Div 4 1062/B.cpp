#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n;
        cin >> n;
        string s, q;
        cin >> s >> q;

        vector<int> found_s(256, 0);
        if (s.size() != q.size())
        {
            cout << "NO" << "\n";
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                found_s[s[i]] += 1;
            }
            bool ok = true;
            for (int j = 0; j < q.size(); j++)
            {
                if (found_s[q[j]] > 0)
                {
                    found_s[q[j]] -= 1;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }

        t -= 1;
    }

    return 0;
}