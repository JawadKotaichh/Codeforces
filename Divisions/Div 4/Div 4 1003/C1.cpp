#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    if (n == 1) {
        cout << "YES\n";
        return;
    }

    int b1 = b[0]; 
    
    bool prev_not_possible = true;
    int prev_not_val = a[0];
    bool prev_flip_possible = true;
    int prev_flip_val = b1 - a[0];

    bool possible = true;

    for (int i = 1; i < n; i++) {
        int curr_not_val = a[i];
        int curr_flip_val = b1 - a[i];

        bool curr_not_possible = false;
        bool curr_flip_possible = false;

        if (prev_not_possible && curr_not_val >= prev_not_val)
            curr_not_possible = true;
        if (prev_flip_possible && curr_not_val >= prev_flip_val)
            curr_not_possible = true;

        if (prev_not_possible && curr_flip_val >= prev_not_val)
            curr_flip_possible = true;
        if (prev_flip_possible && curr_flip_val >= prev_flip_val)
            curr_flip_possible = true;

        if (!curr_not_possible && !curr_flip_possible) {
            possible = false;
            break;
        }

        prev_not_possible = curr_not_possible;
        prev_flip_possible = curr_flip_possible;
        prev_not_val = curr_not_val;
        prev_flip_val = curr_flip_val;
    }

    if (possible && (prev_not_possible || prev_flip_possible))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
