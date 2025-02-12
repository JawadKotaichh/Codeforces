# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    he is given a string s
    if the string has more than 1 letter:
    choose an index i such that s[i]=s[i+1] and replace s[i] with any letter then remove s[i+1]
    Goal: minimum possible lenght he can acheive

*/
int min_length(string s) {
    int n = s.length();
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            return 1; 
        }
    }
    return n;
}


int32_t main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<min_length(s)<<endl;
    }
    return 0;
}