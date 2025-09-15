#include <bits/stdc++.h>
using namespace std;

static inline bool coversWithXY(int x, int y, const vector<pair<int, int>> &p)
{
    for (const auto &pr : p)
    {
        int a = pr.first, b = pr.second;
        if (a != x && a != y && b != x && b != y)
            return false;
    }
    return true;
}

static inline bool tryWithX(int x, const vector<pair<int, int>> &p)
{
    int c = -1, d = -1;
    for (const auto &pr : p)
    {
        if (pr.first != x && pr.second != x)
        {
            c = pr.first;
            d = pr.second;
            break;
        }
    }
    if (c == -1)
        return true;
    if (coversWithXY(x, c, p))
        return true;
    if (coversWithXY(x, d, p))
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<pair<int, int>> p(m);
    for (int i = 0; i < m; ++i)
        cin >> p[i].first >> p[i].second;

    int a1 = p[0].first, b1 = p[0].second;

    if (tryWithX(a1, p) || tryWithX(b1, p))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}
