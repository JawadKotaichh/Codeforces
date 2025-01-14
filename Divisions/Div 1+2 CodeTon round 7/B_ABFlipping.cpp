# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define ll long long
# define int ll
using namespace std;

/*
    Given a string s consisting of A and B only

    we can choose an index i 
    such that s[i]=A and s[i+1]=B and swap(s[i],s[i+1])
    We can do the operations at most once for each index of s

    Goal: The maximum number of operations that we can carry out
*/
int MaxOps(int n,string s){
    int maxNbOps=0;
    int acc=0;
    int pointer=n-1;
    
    while(pointer>=0){
        if(s[pointer]=='B'){
            acc+=1;
        }
        else{
            // Index Of A is pointer
            // Answer+=acc
            if(s[pointer+1]=='B'){
                maxNbOps+=acc;
                acc=1;
                s[pointer]='B';
            }
            else{
                acc=0;
            }
            
        }
        pointer-=1;
    }
    return maxNbOps;
}


int32_t main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s;
        cin>>s;
        cout<<MaxOps(n,s)<<endl;
    }



    return 0;
}