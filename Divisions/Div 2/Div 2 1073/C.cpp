#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007ll
#define endl "\n";
#define input(T, v, n) \
    vector<T> v(n);    \
    for (T &x : v)     \
        cin >> x;
#define print(T, v)       \
    for (T &x : v)        \
        cout << x << " "; \
    cout << endl;
#define TO_BIN(n, v)              \
    for (int i = 31; i >= 0; --i) \
        v.push_back(((n) >> i) & 1);
#define yesno(b)               \
    if (b)                     \
        cout << "YES" << endl; \
    else                       \
        cout << "NO" << endl;
#define inv(b) ([](long long x) {long long r=1,p=MOD-2;while(p){if(p&1)r=r*x%MOD;x=x*x%MOD;p>>=1;}return r; })(b);
#define DIVMOD(a, b) (((a) % MOD) * inv(b) % MOD);

using namespace std;
using ll = long long;
const ll inf = 4e18;

bool bobWins(const string &s)
{
    return s.find("10") == string::npos;
}
void solve()
{
    int n;
    string s;

    cin >> n;
    cin >> s;
    bool ok = true;
    vector<int> ans;
    vector<int> ones;
    vector<int> zeros;

    if (bobWins(s))
        ok = false;
    else
    {
        int z = count(s.begin(), s.end(), '0');
        int o = n - z;
        for (int i = 0; i < z; i++)
        {
            if (s[i] == '1')
                ones.push_back(i);
        }
        for (int i = z; i < n; i++)
        {
            if (s[i] == '0')
                zeros.push_back(i);
        }

        if (ones.size() != 0 && zeros.size() != 0)
        {
            for (int idx : ones)
                ans.push_back(idx);
            for (int idx : zeros)
                ans.push_back(idx);
        }
        else
            ok = false;
    }

    if (ok)

    {

        cout << "Alice" << "\n";
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] + 1 << (i + 1 == ans.size() ? '\n' : ' ');
        }
    }

    else
        cout << "Bob" << "\n";
}

void precompute()
{
}

int main()
{
    precompute();
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}