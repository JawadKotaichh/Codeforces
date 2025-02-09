# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    There is n containers numbered from left to right
    form 1 to n
    The i-th conatainer contains a[i] units of water
    The sum of a[i] is divisble by n
    i<j
    I can transfer water from the i-th container to the j-th container
    Goal: to check if we can make the amount of water in each of the containers equal?

    ex: 4 5 2 1 3
        3 5 2 2 3
        3 4 3 3 3
        sum=15

    ex: 6 5 5 1 3 4 4
        4 5 5 3 3 4 4
        4 4 4 4 4 4 4 

    

*/

bool canEqual(int n,vector<int>a){
    bool equal=true;
    if(n==1) return true;
    else{
        int sumi=accumulate(a.begin(),a.end(),0);
        int waterPerCont = sumi/n;

        int available=0;
        for(int i=0;i<n;i++){
            if(a[i]<waterPerCont){
                if(waterPerCont-a[i]<=available) available-=(waterPerCont-a[i]);
                else return false;
            }
            else{
                available+=a[i]-waterPerCont;
            }

        }
        return true;
        
    }


}

int32_t main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        if(canEqual(n,a)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}