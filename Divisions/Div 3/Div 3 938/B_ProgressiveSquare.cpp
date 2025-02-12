#include <bits/stdc++.h>
#include<algorithm>
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    n by n matrix
    A[1][1] Is the upper left corner element
    a[i+1][j]=a[i][j]+c
    a[i][j+1]=a[i][j]+d




*/

void IsPossible(int n,int c, int d,vector<int>& b){
    bool possible=true;
    map<int,int> freq;
    
    for(int j=0;j<n*n;j++){
        if (freq.find(b[j])!=freq.end()) freq[b[j]]+=1;
        else freq[b[j]]=1;
    }    
    
    
    vector<int> matrix;
    int a11=*min_element(b.begin(),b.end());



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int element = a11 + i * c + j * d; 
            matrix.push_back(element);
        }
    }


    map<int, int> matrix_freq;

    for (int val : matrix) {
        matrix_freq[val]++;
    }

    if (freq == matrix_freq) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}









int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n,c,d; cin>>n>>c>>d;
        vector<int> b(n*n);
        forn(n*n,i) cin>>b[i];
        IsPossible(n,c,d,b);

    }

    return 0;
}
