# include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
# define int long long 
using namespace std;


int32_t main(){
    int t; cin>>t;

    while (t--) {
        int n;
        cin >> n;
        
        int s1;
        if (n - 52 >= 1) {
            s1 = n - 52;
        } else {
            s1 = 1;
        }
        
        int rem = n - s1;

        int s2;
        if (rem - 26 >= 1) {
            s2 = rem - 26;
        } else {
            s2 = 1;
        }
        
        int s3 = rem - s2;

        char c1 = 'a' + s1 - 1;
        char c2 = 'a' + s2 - 1;
        char c3 = 'a' + s3 - 1;

        cout << c1 << c2 << c3 << endl;
    }
    return 0;
}