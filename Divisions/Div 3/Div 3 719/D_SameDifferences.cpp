#include <bits/stdc++.h>
#define forn for(int i=0;i<n;i++)
using namespace std;

/*
    We are given an array of n inetegers and we want to count
    the number of pairs indices (i,j)

    such as i<j and a[j]-a[i]= j-i


*/

int CountNumOfPairs(int n,vector<int>a) {
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]-a[i]==j-i) count+=1;
        }
    }
    return count;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    while (t--)
    {
        int n; cin>>n;
        vector<int>a(n);

        forn cin>>a[i];
        cout<<CountNumOfPairs(n,a)<<endl;
    }
    

    return 0;
}
