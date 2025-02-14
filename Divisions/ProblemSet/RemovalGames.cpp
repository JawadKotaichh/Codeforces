#include <bits/stdc++.h>
#define forn(n,i) for(int i=0;i<n;i++)
using namespace std;

/*
    ex: 1 2 4 5 3
        3 2 5 4 1
        
*/

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    forn( n,i) cin >> a[i];
    forn (n,j) cin >> b[j];
    bool Wins = false;
    if (b == a) Wins = true;
    reverse(b.begin(), b.end());
    if (a == b) Wins = true;
    cout << (Wins ? "Bob" : "Alice") << endl;
    
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
