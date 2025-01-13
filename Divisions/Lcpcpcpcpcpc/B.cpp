#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = acos(-1); // Approximation of pi
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;

// Typedefs
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vbb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define rs resize
#define mp make_pair
#define ar array
#define fr(i, a, n) for(int i = (a); i < (n); ++i)
#define rf(i, m, n) for(int i = (m); i >= (n); --i)
#define trav(x, a) for(auto& x : a)
#define sz(x) (int)(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define scan(a, n) fr(i, 0, n) cin >> a[i]
#define II() ({int a; scanf("%d", &a); a;})

// Debug
#define debug(x) cout << #x << " = " << x << endl;

// Operator overloads
template<typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    return is >> p.first >> p.second;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& it : v) is >> it;
    return is;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << p.first << " " << p.second;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& c) {
    for(const auto& it : c) os << it << " ";
    return os;
}
template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "{ ";
    for (const auto& pair : m) {
        os << pair.first << ": " << pair.second << ", ";
    }
    os << "}";
    return os;
}

// Utility functions
template<typename T>
void print(const T& t) { cout << t << "\n"; }

template <typename T>
void printArray(const T arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Sorting
bool sort_asc(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
bool sort_desc(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}



long long factorial(int num, int MOD) {
    long long result = 1;
    for (int i = 2; i <= num; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

long long modInverse(long long a, int MOD) {
    long long result = 1, base = a;
    int exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

long long nCr(int n, int r, int MOD) {
    if (r > n) return 0;
    long long numerator = factorial(n, MOD);
    long long denominator = (factorial(r, MOD) * factorial(n - r, MOD)) % MOD;
    return (numerator * modInverse(denominator, MOD)) % MOD;
}

void solve() {

	int n, x; cin >> n >> x;

	vi v(n); cin >> v;

	int x0 = 0,x1 = 0;

	trav(a,v) {
		if (a == 1) x1 ++;
	}

	x0 = n - x1;


	long long totalGroups = 0;

    

    for (int k = 1; k <= x0; k++) {
        totalGroups = (totalGroups + nCr(x0, k, MOD)) % MOD;
    }
    if (x1 < x) {
    	cout << totalGroups % MOD << endl;
    	return;
    }	


    long long answer = 0;
    for (int i = x; i <= x1; i += x) {
        // Number of ways to form groups of size 1 for this multiple
        long long groupsOfOne = nCr(x1, i, MOD);
        answer = (answer + (groupsOfOne) % MOD) % MOD;
        answer = (answer + (groupsOfOne * totalGroups) % MOD) % MOD;
    }

    cout << (answer + totalGroups) % MOD << endl;

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    FASTIO;

    int t = 1;
    cin >> t; 

    while(t--) {
        solve();
    }

    return 0;
}

/**/