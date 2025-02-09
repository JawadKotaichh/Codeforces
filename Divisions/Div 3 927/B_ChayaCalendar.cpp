# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    There is n signs
    The i-th sign occurs every a[i] years
    They have to happen sequentially, the first occur then strictly after it the second will occur


    Goal is to know in which year will the occurence of the n-th sign 

*/

int year(int n,vector<int> a){
    int y=0;
    int last=a[0];
    y+=last;

    for(int i=1;i<n;i++){
        if (a[i] <= y) {
            y = ((y / a[i]) + 1) * a[i];
        } else {
            y = a[i];
        }
    }
    return y;

}

int32_t main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        cout<<year(n,a)<<endl;
    }
    return 0;
}