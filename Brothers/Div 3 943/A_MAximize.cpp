# include <bits/stdc++.h>
using namespace std;
/*
    We are given an integer x and our task is to find 
    y such as gcd(x,y)+y is maximum possible
    1=<y<x

    10: 1,2,5,10
    5: 1,5
    gcd=5
    gcd+y=10

    7: 1,7
    6: 1,7
    
    To maximize gcd(x,y)+y
    gcd(x,y) is maximal so if I can get 
    

*/


int Y(int x){
    int y;
    int MaxScore=0;
    int currSCore=0;

    for(int i=1;i<x;i++){
        currSCore=gcd(x,i)+i;
        if (currSCore>MaxScore) {
            MaxScore=currSCore;
            y=i;
        }
    }
    return y;


}

int main(){
    int t; cin>>t;

    while(t--){
        int x; cin>>x;
        cout<<Y(x)<<endl;
    }
    return 0;
}