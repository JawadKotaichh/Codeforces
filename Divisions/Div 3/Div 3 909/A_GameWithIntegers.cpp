#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    Players are given an integer n

    At each turn he can choose to add 1 to the current integer or substract one
    if after Vanya move the integer is divisible by 3 then Vanya Wins
    else Vova wins

    

*/
string Winner(int n){
    if((n+1)%3==0 or (n-1)%3==0) return "First";
    else return "Second";
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n; cin>>n;
        cout<<Winner(n)<<endl;
        
    }

    return 0;
}
