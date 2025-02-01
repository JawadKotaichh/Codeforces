# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;




bool Tenacity(int n, vector<int>a){
    int countOnes=0;
    int countOfmini=0;
    int mini=a[0];
    
    for(int i=0;i<n;i++){
        if(a[i]<mini) mini=a[i];
        if(a[i]==1) countOnes+=1;
    }

    if(countOnes>1) return false;
    else if(countOnes==1) return true;
    else{

        for(int j=0;j<n;j++) if(a[j]==mini) countOfmini+=1;
        
        if(countOfmini==1) return true;
        else{
            for(int j=0;j<n;j++){
                if(a[j]!=mini){
                    int curr=a[j]%mini;
                    if(curr<mini and curr!=0){
                        return true;
                    }
                }
            }
            
        }
    }
    return false;
}


int32_t main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        if (Tenacity(n,a)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}