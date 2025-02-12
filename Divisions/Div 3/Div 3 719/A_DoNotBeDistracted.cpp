# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    After finishing a task he cannot return to the previous task


    
*/
void CheckIfSuspicious(int n,string s){
    map<char,int> LastSeenIndex;
    bool IsSuspicious =false;

    for(int i=0;i<n;i++){
        if(LastSeenIndex.find(s[i])!=LastSeenIndex.end()){
            // element already seen
            if (LastSeenIndex[s[i]]!=(i-1)){
                IsSuspicious=true;
                break;

            }
        }
        LastSeenIndex[s[i]] = i;
    }
    if (IsSuspicious) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        CheckIfSuspicious(n,s);
    }
    return 0;
}