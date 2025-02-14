#include <bits/stdc++.h>
# define forn(n,i) for(int i=0;i<n;i++)
using namespace std;


/*
    He prepared n boxes
    The i-th box weighs a[i] tons
    Each truck must hold k boxes


    

*/

int MaxDiff(int n, vector<int> a){
    int diff=0;
    int maxi=0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) { 
            int numberOfTrucks = n / i;
            int CurrMini = INT_MAX;
            int currMaxi = INT_MIN;

            for (int j = 0; j < n; j += i) { 
                CurrMini = min(CurrMini, *min_element(a.begin() + j, a.begin() + j + i));
                currMaxi = max(currMaxi, *max_element(a.begin() + j, a.begin() + j + i));
            }
            maxi = max(maxi, currMaxi - CurrMini);
        }
    }

    return maxi;
}



int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n; cin>>n;
        vector<int>a(n);
        forn(n,i) cin>>a[i];
        cout<<MaxDiff(n,a)<<endl;
        
    }

    return 0;
}
