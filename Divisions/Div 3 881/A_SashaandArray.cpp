# include<iostream>
# include <algorithm>
# include <vector>
# define forn(n,i) for (int i=0;i<n;i++)
# define v vector
using namespace std;



/*
    For each color there should be at least one element of this color
    The cost for the color is max(S)-min(S) S is the sequence of elments in that color
    We need to have the maxmimum possible cost

*/

int MaxiCost(int n, v<int> lst){
    sort(lst.begin(),lst.end());

    int l=0;
    int r=n-1;
    int maxCost=0;

    while(l<=r){
        int currCost=lst[r]-lst[l];
        maxCost+=currCost;
        l+=1;
        r-=1;
    }
    return maxCost;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin>>n;
        v<int> lst(n);
        forn(n,i) cin>>lst[i];
        if (lst.size()==1) cout<<0<<endl;
        else cout<<MaxiCost(n,lst)<<endl;
    }
    return 0;
}