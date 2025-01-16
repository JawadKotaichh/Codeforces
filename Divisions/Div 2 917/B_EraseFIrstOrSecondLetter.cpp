# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    We are given a string s
    We can remove the first character of the string or the second one in one operation 
    Our Goal is to find the number of distinct strings that can be generated by applying these ops

    ex: ababa
    3 a's and 2 b's answer --->3**2

    ex: bcdaaaabcdaaaa
    aaaaaaaabbccdd
    8 a, 2 b, 2 c, 2d
*/


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        sort(a.begin(),a.end());
        minOps(n,a);
    }
    return 0;
}