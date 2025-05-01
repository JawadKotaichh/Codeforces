# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;
/*
    Your are given a 4-digit code of integers from 0 to 9
    In one move:I can print the current digit
                I can move to any adjacent digits
                Each operation costs 1 second

    Ex: 1111 ->4 
    1236 -> 1 + 2 + 2 + 4 -> 9


*/

int HADI(string s){

    int last = s[0]-'0';
    int minCount=0;
    if(last==0) {
        minCount += 10;
        last =10;
    }
    else minCount+=last;

    for(int i=1;i<s.size();i++){
        int current = s[i] - '0'; 

        if(current!=0){
            minCount+= abs((last - current))+1;
            last = current;
        }
        else{
            current=10;
            minCount+= abs((last- current))+1;
            last = current;
        }
        
    }

    return minCount;
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;


    while(t--){
        string s;
        cin>>s;
        cout<<HADI(s)<<endl;
    }

    return 0;
}