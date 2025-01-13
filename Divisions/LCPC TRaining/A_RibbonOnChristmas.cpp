# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define ll long long

using namespace std;

/* 
    in one step you can spend 50 or 100

    0 0 0 0 0

    1 1 1 1 1
    1 2 2 2 1
    1 2 3 2 1

    1 20 100 1 20 20 100 100 20 20
    
    0 0 0 0 0 0 0 0 0 0 
    
    1 1 1 1 1 1 1 1 1 1 (+1 step)
    1 20 20 1 20 20 20 20 20 20 20 (+2 steps)
    1 20 100 1 20 20 20 100 100 20 20 (+2 steps)


    AB Flipping

*/

int least(int n, vector<int>lst){
    int curr=0;
    int Sum=0;
    map<int,int>D;

    for(int i=1;i<n;i++){
        if (lst[i]!=lst[i-1]){
            Sum+=1;
            D[lst[i]]=1;
        }

        if(D.find(lst[i])==D.end()){
            Sum+=1;
            D[lst[i]]=1;
        }
        
    }
    return Sum;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<int>lst(n);
    forn(n,i) cin>>lst[i];
    cout<<least(n,lst)<<endl;
    
}