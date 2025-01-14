# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define ll long long
# define int ll
using namespace std;

/*
    I can select an indec i from 2 to n-1 such that 
    a[i-1]<a[i] and a[i]>a[i+1] and swap a[i] and a[i+1]
    Our goal is to know if it can be sorted after a finite number of operations
    Thee list contains the number from 1 to n
    
    First Observation is that if the list does not starts with 1-->NO

*/

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>lst(n);
        for(int i=0;i<n;i++) cin>>lst[i];

        if(lst[0]!=1) cout<<"NO"<<endl;
        else{cout<<"YES"<<endl;}
    }
}