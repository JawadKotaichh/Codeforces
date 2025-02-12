# include<iostream>
# include <algorithm>
# include <vector>
# include<map>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;

/*
    We are given a number n and our goal is count the sum of vertex numbers on the path from the root to that vertex.

*/
map<long long, long long> memo;
long long sumOfBinaryTree(long long n){
    if(n==1) return 1;
    
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    else{
        if (n%2==0){
            memo[n]= sumOfBinaryTree(n/2)+n;
        }
        else{
            memo[n]= sumOfBinaryTree((n-1)/2)+n;
        }
    }
      
    
    return memo[n];
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        long long n;
        cin>>n;
        cout<<sumOfBinaryTree(n)<<endl;
    }

    return 0;
}