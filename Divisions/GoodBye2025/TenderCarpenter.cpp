// A set of integer is stablke iff for any possible u, w,v
// sticks of thse length can form a non-degenerate triangle
// u+v>w
// v+w>u
// w+u>v this means that we have a non degenerate triangle
// Yes if we can partition a at least two different ways
// else NO

#include <bits/stdc++.h>
# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        bool found=false;
        
        for(int i=1;i<n;i++){
            int mini=min(arr[i],arr[i-1]);
            int maxi=max(arr[i],arr[i-1]);
            if (2*mini>maxi) {
                found=true;
                break;
            }
        }
        if (found) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}



