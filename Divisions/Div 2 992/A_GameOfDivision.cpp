# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    We are given an array a and an integer k
    There is two players playing a game
    First player choose an index i and the second another index j such as j!=i
    The first player wins if abs(a[i]-a[j]) is not divisble by k
    Our goal is to determine if it is possible for the first player to win.

    So we need to check if there is an element of a at index i
    such that if we pick j!=i for all other indexes,
    abs(a[i]-a[j]) not divisible by k

    
*/
void WhoWins(int n,int k,vector<int>a){
    int count=0;
    int indx;
    bool Wins=false;

    for(int i=0;i<n;i++){
        //cout<<"a[i]= "<<a[i]<<" INDEX= "<<i<<endl;
        for(int j=0;j<n;j++){
            if (j!=i){
                //cout<<"diff= "<<abs(a[i]-a[j])<<endl;
                if(abs(a[i]-a[j])%k!=0){
                    count+=1;
                }
                else{
                    break;
                }
            }
            
        }
        // cout<<"COUNT= "<<count<<endl;
        if(count == n-1){
            Wins=true;
            indx=i+1;
            break;
        }
        count=0;
    }

    if(Wins){
        cout<<"YES"<<endl;
        cout<<indx<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;cin>>n>>k;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        WhoWins(n,k,a);
    }
    return 0;
}