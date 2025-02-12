# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    
*/



int32_t main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        string  lastThree = s.substr(s.size() - 2);
        if(lastThree[1]=='s'){
            cout<<s.substr(0,s.size()-2)<<"i"<<endl;
        }
        else cout<<s.substr(0,s.size()-1)<<"us"<<endl;
    }
    return 0;
}