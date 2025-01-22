# include<bits/stdc++.h>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;


/*
    We are given an array a of n integers
    you can pick any index from 2 to n-1
    a[i-1] -= 1, a[i+1] +=1
    or:
    a[i-1] += 1, a[i+1] -= 1

    ex: 3 2 1   --> 2 2 2 
    ex: 1 2 5 4 --> 3 2 3 4---> 3 3 3 3 Yes
    ex: 1 6 6 1--> 3 4 4 3 impossible
    ex: 6 2 1 4 2---> 3 2 4 4 2--> 3 3 4 3 2
    ---> 3 3 3 3 3  YES



*/
void Possible(int n, vector<int> a){
    bool isPossible=true;
    
    for(int i=1;i<n-1;i++){
        if (a[i-1]!=a[i+1]){
            int sum=a[i-1]+a[i+1];
            cout<<"A[i-1]= "<<a[i-1]<<endl;
            cout<<"A[i+1]= "<<a[i+1]<<endl;

            if (sum%2==0){
                a[i+1]=a[i-1]=sum/2;
            }
        }
        for(int j=0;j<n;j++) cout<<a[j]<<" ";
        cout<<endl;
    }

    for(int j=1;j<n;j++){
        if (a[j]!=a[j-1]){
            isPossible=false;
            break;
        }
    }
    if (isPossible) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        Possible(n,a);
    }
    return 0;
}