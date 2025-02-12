# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    We have n consecutive cells
    each one of them can be:
    -empty
    -contains thorns
    -coin
    
    In one move I can move 1 or 2 cells (providing that the destination cell does not contains throns)
    Goal: Find the max number of coins you can collect

*/
int maxNumOfCoins(int n,vector<char> s){
    int maxCoins=0;
    // '.' empty cell / '@' coin / '*' Thron
    // if there is two throns consecutive the game stops
    int pointer =0;
    while (pointer<n-1){
        if(s[pointer+1]=='@'){
            maxCoins+=1;
            pointer+=1;
        }else if (s[pointer+1]=='.') pointer+=1;
        else{
            if(s[pointer+2]!='*'){
                
                if(s[pointer+2]=='@') maxCoins+=1;
                pointer+=2;
            }
            else break;
        }
        
    }
    return maxCoins;

}

int32_t main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<char> s(n);
        forn(n,i) cin>>s[i];
        cout<<maxNumOfCoins(n,s)<<endl;
    }
    return 0;
}