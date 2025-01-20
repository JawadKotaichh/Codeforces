# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    We are given a string s 
    He has two strips, the first can hold m chars
    and the second as many as needed

    
*/
int Breaks(int n, int m, vector<string> a){
    int score=0;

    for(int i=0;i<n;i++){
        int size = a[i].size();
        if(m>=size) {
            m-=size;
            score+=1;
        }
        else break;
    }


    return score;
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<string> a(n);
        forn(n,i) cin>>a[i];
        cout<<Breaks(n,m,a)<<endl;
    }
    return 0;
}