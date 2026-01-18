#include <bits/stdc++.h>
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

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    input(ll, base, n);
    vector<ll> add(n, 0);
    vector<int> seen(n, 0);
    int ver = 1;

    for (int i = 0; i < m; i++)
    {
        int bi, ci;
        cin >> bi >> ci;
        ll curr;
        if (seen[bi - 1] != ver)
            curr = base[bi - 1];
        else
            curr = base[bi - 1] + add[bi - 1];
        if (curr + ci > h)
        {
            ver++;
        }
        else
        {
            if (seen[bi - 1] != ver)
            {
                seen[bi - 1] = ver;
                add[bi - 1] = 0;
            }
            add[bi - 1] += ci;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll ans;
        if (seen[i] == ver)
            ans = base[i] + add[i];
        else
            ans = base[i];
        cout << ans << (i + 1 == n ? '\n' : ' ');
    }
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