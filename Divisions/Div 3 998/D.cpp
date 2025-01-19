#include<bits/stdc++.h>
#define forn(n, i) for (int i = 0; i < n; i++)
#define v vector
using namespace std;
/*
    We are given an array aof n integers
    Select index i and mini=min(a[i],a[i+1])
    and make a[i]-=mini, a[i+1]-=mini

    Our Goal is to determine if it is possible to make the sequence in non decreasing order

*/


void Possible(int n, vector<int>& a) {
    for(int i=0;i<n-1;i++){
        if (a[i+1]>a[i]){
            int mini=min(a[i],a[i+1]);
            a[i]-=mini;
            a[i+1]-=mini;
        }
    }

    bool isPossible=true;
    for(int j=0;j<n-1;j++){
        if (a[j]>a[j+1]) {
            isPossible=false;
            break;
        }
    }
    if (isPossible) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(n,i) cin >> a[i];
        Possible(n, a);
    }
    return 0;
}
