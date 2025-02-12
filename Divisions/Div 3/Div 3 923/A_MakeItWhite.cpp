# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;


int32_t main(){
    int t; cin>>t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin>>s;
        int count=0;
        int firstB=0;
        int lastB=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B' && count==0){
                firstB=i;
                count+=1;
            }
            if(s[i]=='B' && count!=0){
                lastB=i;
            }
            
        }
        cout<<lastB-firstB +1<<endl;
           
    }
    return 0;
}