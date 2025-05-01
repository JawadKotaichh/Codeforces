# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;
/*
   Given an array of integers a and a number k

   In one Operation:
   choose index i and a[i]+=1

    Goal: Find the min number of ops to make the product of all the numbers divisble by k

    ex: 
    a=[7,3] k = 5
    product 0 or multiple of k( the min should be k)


*/

int HADI(vector<int> a,int k){
    
    if(k==4){ // we need two even numbers 
        int n=a.size();
        int countEven=0;

        if(n<=1) {
            int modK=a[0]%k;
            return k-modK;
        }
        int rem = k;
        forn(n,i){
            if(a[i]%2==0){
                countEven+=1;
                if(countEven == 2) break;
            }
            if(a[i]%k== 0) return 0;
            int modK=a[i]%k;
            rem = min(k-modK,rem);
        }
        if(countEven >= 2) return 0;
        else return min(2-countEven,rem);
        
    }
    else{
        int n = a.size();
        int rem = k;

        forn(n,i){
            if(a[i]%k==0) return 0;
            int modK=a[i]%k;
            rem = min(k-modK,rem);
        }        
        return rem;
    }
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;


    while(t--){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n,k; cin>>n>>k;
        vector<int>a(n);
        forn(n,i) cin>>a[i];
        cout<<HADI(a,k)<<endl;
    }

    return 0;
}