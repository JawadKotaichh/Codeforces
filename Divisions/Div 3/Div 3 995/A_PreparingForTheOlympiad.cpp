# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    There is n days left until the Olympiad
    On the i-th day Monocarp solve a[i] problems
    Stereocarp will solve b[i] problems

    If Monocarp trained on day i, Stereocarp will train on day i+1 only if i!=n
    Our goal is to maximize the difference between the number of problems Monocarp and Stereocarp
    Maximize m-s
    
    ex: a=[3,2]
        b=[2,1]

    So we want to check if the next day is as small as possible


*/

int MaxDiff(int n, vector<int> a, vector<int> b){
    int TotSum=0;
   

   for(int i=0;i<n-1;i++){
        if(a[i]>b[i+1]) TotSum+=(a[i]-b[i+1]);
   }
   TotSum+=a[n-1];
   return TotSum;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        forn(n,i) cin>>a[i];
        forn(n,i) cin>>b[i];
        cout<<MaxDiff(n,a,b)<<endl;
    }
    return 0;
}