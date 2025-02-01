# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;
/*
    We are given an array of integers
    Ee want to do the 2ops :
    first: arbitrary rearrrange the order of the elements or leave it 
    second: Chosse one contigous segment of elements and replace the signs of all thoses elements whit their opposite
    
    Goal: What is the maximum sum of the array after performing these two ops
    

*/




int32_t main(){
    int t; cin>>t;

    while(t--){
        int n; cin>> n;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        int score=0;
        for(int j=0;j<n;j++){
            if (a[j]<0) score+=-a[j];
            else score+=a[j];
        }
        cout<<score<<endl;
    }
    return 0;
}