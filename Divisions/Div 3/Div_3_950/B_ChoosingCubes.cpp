#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long
using namespace std;

/*
    We have n cubes numbered from left to right from 1 to n
    The cube with index f is favorite

    He arragend the cubes in increasing order of their values 
    He removed the first k elements of the sorted list
    He needs to know if his favorite cube is removed or not

    4 3 3 2 3
    2 3 3 3 4 --> k=2 and f=2--> Maybe

    4 2 1 3 5
    1 2 3 4 5 --> f=5 and k=3 --> Yes

    5 2 4 1 3
    1 2 3 4 5 --> f=5 and k=2 --> NO


*/

void ChoosingCubes(int n,int f,int k,vector<int> a){
    int favorite =a[f-1];
    int count=0;
    int firstCount=0;
    bool remove =false;
    sort(a.rbegin(),a.rend());
    //cout<<"Sorted Array: ";
    //forn(n,i) cout<<a[i]<<" ";
    //cout<<endl;
    

    for(int x=0;x<n;x++){
        if(a[x]==favorite) count+=1;
    }
    firstCount=count;
    // cout<<"INITIAL COUNT= "<<count<<endl;

    for(int j=0;j<k;j++){
        if(a[j]==favorite){
            //cout<<"a[j]= "<<a[j]<<endl;
            if (count==0){
                remove=true;
                break;
            }
            else{
                count-=1;
                if (count ==0) break;
            } 
            //cout<<"Remainig Count = "<<count<<endl;
        }
    }

    if(count==firstCount){
        cout<<"NO"<<endl;
    }
    else if (count==0){
        cout<<"YES"<<endl;
    }
    else cout<<"MAYBE"<<endl;
}


int32_t main() {
    int t; 
    cin >> t;

    while (t--) {
        int n,f,k;
        cin >> n >> f >>k;
        vector<int> a(n);
        forn(n,i) cin>>a[i];
        ChoosingCubes(n,f,k,a);
    }

    return 0;
}
