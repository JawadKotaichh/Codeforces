#include <bits/stdc++.h>
using namespace std;

static vector<int> kmp_pi(const string &p)
{
    int n = (int)p.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

static vector<int> kmp_find(const string &text, const string &pat)
{
    vector<int> occ;
    if (pat.empty() || text.size() < pat.size())
        return occ;
    vector<int> pi = kmp_pi(pat);
    int j = 0;
    for (int i = 0; i < (int)text.size(); ++i)
    {
        while (j > 0 && text[i] != pat[j])
            j = pi[j - 1];
        if (text[i] == pat[j])
            ++j;
        if (j == (int)pat.size())
        {
            occ.push_back(i - (int)pat.size() + 1); // starting index
            j = pi[j - 1];
        }
    }
    return occ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<string> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        string y;
        cin >> x >> y;
        const string &s = A[x - 1];
        int m = (int)y.size();

        // All occurrences of y in s
        vector<int> pos = kmp_find(s, y);

        // Count runs with step m
        long long ans = 0;
        long long run = 0;
        int prev = INT_MIN;
        for (int idx : pos)
        {
            if (run > 0 && idx == prev + m)
            {
                ++run;
            }
            else
            {
                if (run > 0)
                    ans += run * (run + 1) / 2;
                run = 1;
            }
            prev = idx;
        }
        if (run > 0)
            ans += run * (run + 1) / 2;

        cout << ans << '\n';
    }
    return 0;
}
