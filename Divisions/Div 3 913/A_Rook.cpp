#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    

*/


int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        string pos;
        cin>>pos;

        for(int i=1;i<9;i++){
            if(i!=stoi(pos.substr(1))){
                cout<<pos[0]<<i<<endl;
            }
        }
        
        string s="abcdefgh";

        for(char c=s[0]; c<'i'; c++){
            if(c!=pos[0]){
                cout<<c<<pos[1]<<endl;
            }
        }
        
    }

    return 0;
}
