# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    We are given an array a 
    We can change a[i] to any number between 0 and a[i]
    if a[i]<0 replace a[i] with any integer from a[i] to 0
    
    r is the min possible product of the array
    our goal is to have the minimum number of operations to makle the product equal to r

    if 0 is in the array the answer is 0
    else if there is an odd number of negative number, we dont need any operation
    else make one of them 0 the answer 1 
*/
void minOps(int n,vector<int>a){
    if(a[0]==0) cout<<0<<endl;
    else{
        int numberOfNeg=0;
        forn(n,i){
            if(a[i]<0) numberOfNeg+=1; 
        }
        if (numberOfNeg%2!=0) cout<<0<<endl;
        else{
            cout<<1<<endl;
            cout<<1<<" "<<0<<endl;
        }
    }
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        sort(a.begin(),a.end());
        minOps(n,a);
    }
    return 0;
}