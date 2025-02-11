# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;
/*
    the ith letter correspond to the problem he was solving during the ith minute
    ACBCBC
    tot=6
    1 3 2

    AAAAFPC
    1111(6)(15)3
    
    Abb
    AABB


    tot=7
    A,


    So if the we have the same letters consecutive then each one is 

*/
int problemSolved(int n, string s){
        //return letter - 'A' + 1; 
        
        int count=0;
        map<char,int> Counter;
        set<char> AlreadySolved;

        forn(n,i) {
            int curr = s[i] - 'A'+ 1;
            if (AlreadySolved.find(s[i]) == AlreadySolved.end()) {  
                    Counter[s[i]]+=1;
            }
            if(Counter[s[i]]==curr && AlreadySolved.find(s[i]) == AlreadySolved.end() ){
                AlreadySolved.insert(s[i]);
                count+=1;
            }
        }

        return count;
}



int32_t main(){
    int t; cin>>t;

    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        cout<<problemSolved(n,s)<<endl;

    }
    return 0;
}