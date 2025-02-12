# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
#define int long long
using namespace std;


/*
    
    The machine accepts only 2 coins, the sum of which does not exceed k

    Rudolf has two pockets with coins
    In the left pocket there are n coins dominations array b
    In the right pocket there are m coins with dominations c
    He should take one coin from the left and one from the right pocket

    How many ways can we select 2 coins from c and b, should be b+c <= k



*/

int numberOfWays(int n,int m,int k,vector<int>a,vector<int>b){
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]+b[j]<=k) counter+=1;
        }
    }
    return counter;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        vector<int> b(n);
        vector<int> c(m);
        forn(n,i) cin>>b[i];
        forn(m,i) cin>>c[i];
        cout<<numberOfWays(n,m,k,b,c)<<endl;
    }
    return 0;
}