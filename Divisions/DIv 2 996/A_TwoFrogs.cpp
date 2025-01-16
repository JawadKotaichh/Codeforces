# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    We are given an array a from 1 to n
    Alice starts then Bob
    
*/

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int maxi=max(a,b);
        int mini=min(a,b);
        if ((maxi-mini)%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}