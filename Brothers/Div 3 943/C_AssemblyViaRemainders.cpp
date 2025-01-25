# include <bits/stdc++.h>
# define int long long
using namespace std;
/*
    We have an array of n integers X

    Our task is to get the array where x[i]= a[i] % a[i-1] 2<=i<=n
    size of a is more than x by 1

    ex: x=[2,4,1]
    a= [3,5,4,9]

    x[0]=5%3=2
    x[1]=4%5=4
    x[2]=9%4=1


    ex: x=[1,1]

    x[0] = a[1]%a[0]=1
    x[1] = a[2]%a[1]=1

    a[i] % a[i-1] =c 
    a[i-1] = cst*a[i-1] + c
    and c here is x[i]




*/


void getModArray(int n,vector<int> X){
    vector<int> ModVect(n);
    ModVect[0]=X[0]+1;

    for(int i=0;i<n-2;i++){
        int diff=X[i+1]-X[i];

        // cout<<"diff= "<<diff<<endl;
        
        if (diff>=0){
            int c=((diff)/(ModVect[i]))+1;

            int curra= (c*ModVect[i])+X[i];

            ModVect[i+1]=curra;

            // c>diff/a[i-1]
        }
        
        else{
            ModVect[i+1]=X[i];
        }
    }

    ModVect[n-1]=X[n-2];
    

    for(int j=0;j<n;j++) cout<<ModVect[j]<<" ";
    cout<<endl;

}

int32_t main(){
    int t; cin>>t;

    while(t--){
        int n;cin>>n;
        vector<int> X(n-1);
        for(int i=0;i<n-1;i++) cin>>X[i];

        getModArray(n,X);
       
    }
    return 0;
}