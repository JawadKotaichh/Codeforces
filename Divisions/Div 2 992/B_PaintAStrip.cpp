#include <bits/stdc++.h>
using namespace std;
#define v vector


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--){
                 int n; cin >> n;
                 int ans = 1;
                 for (int i = 1; i < n; i = (i + 1) << 1)
                     ans++;
                 cout << ans << endl;
    }
}