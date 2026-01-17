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

ll mex(const vector<ll> &arr)
{
    unordered_set<ll> s(arr.begin(), arr.end());
    ll m = 0;
    while (s.count(m))
    {
        m++;
    }
    return m;
}

void solve()
{
    int n;
    cin >> n;
    bool ok = true;
    input(ll, a, n);

    if (ok)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
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