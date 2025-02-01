# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;

/*
    We are given 3 integers a,b,l (all positive)

    It exists always k,x,y(positives) such as l = k * (a**x) * (b**y)

    Goal is to find the number of distinct possible values of k

*/


int numberOfDistinctK(int a,int b,int l){
    set<int> k_values;


    for(int x=0;pow(a, x)<=l;x++){
        int powerOfA=pow(a,x);

        if (l % powerOfA != 0) break;
        
        for(int y=0;pow(b,y)<=l;y++){
            int powerOfB=pow(b,y);

            if(l%(powerOfB*powerOfA)==0){
                k_values.insert(l/(powerOfA*powerOfB));
            }
        }
    }

        
    return k_values.size();

}


int32_t main(){
    int t; cin>>t;

    while(t--){
        int a,b,l; cin>>a>>b>>l;
        cout<<numberOfDistinctK(a,b,l)<<endl;
    }
    return 0;
}