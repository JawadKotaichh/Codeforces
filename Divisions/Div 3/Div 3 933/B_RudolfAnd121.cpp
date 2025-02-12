# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
# define int long long
using namespace std;


/*
    
    We have an array of n integers numbered from 1 to n
    we can choose any index other than the first elemnt and make
    a[i-1]-=1
    a[i]-=2
    a[i+1]-=1

    Goal: Can we make all the elements equal to zeros ?
    
    ex: 
    1 3 5 5 2
    1 2 3 4 2
    0 0 2 4 2
    0 0 0 0 0

    1 3 5 5 2
    0 1 4 5 2 
    0 0 2 4 2
    0 0 0 0 0
    
    
    





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