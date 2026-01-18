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

ll mex_sort(vector<ll> a)
{
    sort(a.begin(), a.end());
    ll m = 0;
    for (ll x : a)
    {
        if (x < 0)
            continue;
        if (x == m)
            m++;
        else if (x > m)
            break;
    }
    return m;
}

void solve()
{
    int n;
    cin >> n;
    bool ok = true;
    input(ll, a, n);
    vector<ll> b;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    long long best = 1, cur = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[i - 1] + 1)
            cur++;
        else
            cur = 1;
        best = max(best, cur);
    }

    cout << best << "\n";
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