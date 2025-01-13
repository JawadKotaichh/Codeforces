#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ln '\n'
typedef long long ll;
int main()
{
    int n,x;
    cin>>n>>x;
    map<int,int> Dictionary;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        if (Dictionary.count(x-value)){
            cout<<i+1<<" "<<Dictionary[x-value]<<endl;
            return 0;
        }
        Dictionary[value]=i+1;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}