# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
# define int long long
using namespace std;


/*
    a[i] is the initial units of material i
    Select an index i and spend 1 material from all others exept i
    a[i] = a[i] + 1 and all b[j] = b[j]-1

    our goal is to check if it is possible to do array a as b in any number of ways
    Only one element we can add to it and all the others take from it
    
*/

void solve(){
    int n; cin >> n;
    v<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    v<int> differences(n);
    for (int i = 0; i < n; i++){
        differences[i] = (b[i] - a[i]);
    }
    sort(differences.begin(),differences.end());
    
    int count = 0;
    for (int i = 0; i < n; i++){
        if (differences[i] > 0) count++;
    }

    if (count > 1){
        return void(cout << "NO" << endl);
    }


    for (int i = 0; i < n; i++){
        if (abs(differences[i]) < differences[n - 1]){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    int t = 0;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}