# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    we are given:
    n:len(a), m:len(b), 
    k:the number where we should choose k/2 elements from every elements
    and check if we can have the list of number from 1 to k

*/

bool isPossible(int n,int m,int k,vector<int>a,vector<int>b){
    bool poss=true;
    int numOfElemnts=k/2;

    map<int,int> availableA;
    map<int,int> availableB;

    
    for(int i=0;i<n;i++){
        if(a[i]>0 && a[i]<k+1) availableA[a[i]]+=1;
    }
    
    for(int j=0;j<m;j++){
        if(b[j]>0 && b[j]<k+1) availableB[b[j]]+=1;
    }

    


    


    return true;

}

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        vector<int>a(n);
        vector<int>b(m);
        forn(n,i) cin>>a[i];
        forn(m,j) cin>>b[j];
        if(isPossible(n,m,k,a,b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}