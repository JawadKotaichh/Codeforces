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

#define debug(x) cout << #x << " = " << x << endl;

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

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int count_ones(int n) {
    return __builtin_popcount(n);
}

vector<int> precompute_special_numbers(int maxx) {
    vector<int> special_numbers;
    int current_number = 1;

    while (sz(special_numbers) < maxx) {
        int one_bits_count = count_ones(current_number);
        if (is_prime(one_bits_count)) {
            special_numbers.push_back(current_number);
        }
        current_number++;
    }

    return special_numbers;
}

int find_nth_special_number(int n, const vector<int>& special_numbers) {
    if (n <= sz(special_numbers)) {
        return special_numbers[n - 1];
    } else {
        int current_number = special_numbers.back() + 1;
        int count = sz(special_numbers);
        while (count < n) {
            int one_bits_count = count_ones(current_number);
            if (is_prime(one_bits_count)) {
                count++;
                if (count == n) {
                    return current_number;
                }
            }
            current_number++;
        }
    }
    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    
    int maxx = 10; 
    vector<int> special_numbers = precompute_special_numbers(maxx);

    while (t--) {
        int n;
        cin >> n;
        cout << find_nth_special_number(n, special_numbers) << endl;
    }

    return 0;
}