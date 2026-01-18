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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    input(ll, robots, n);
    input(ll, b, m);
    string ops;
    cin >> ops;
    unordered_map<long long, int> earliest;
    ll tot = 0;
    for (int i = 0; i < k; i++)
    {
        if (ops[i] == 'L')
            tot -= 1;
        else
            tot += 1;
        if (!earliest.count(tot))
            earliest[tot] = i + 1;
    }
    sort(b.begin(), b.end());

    vector<int> deaths(k + 2, 0);

    for (long long robot : robots)
    {
        long long loPos = robot - k;
        long long hiPos = robot + k;

        int L = lower_bound(b.begin(), b.end(), loPos) - b.begin();
        int R = upper_bound(b.begin(), b.end(), hiPos) - b.begin();

        int best = INT_MAX;
        for (int idx = L; idx < R; idx++)
        {
            long long diff = b[idx] - robot;
            auto it = earliest.find(diff);
            if (it != earliest.end())
            {
                best = min(best, it->second);
                if (best == 1)
                    break;
            }
        }
        if (best != INT_MAX)
            deaths[best]++;
    }
    int dead = 0;
    for (int i = 1; i <= k; i++)
    {
        dead += deaths[i];
        int alive = n - dead;
        if (i > 1)
            cout << ' ';
        cout << alive;
    }
    cout << '\n';
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