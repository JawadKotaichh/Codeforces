#include <bits/stdc++.h>
#define int long long
#define NEXT_POWER_OF_2(n) (n <= 1 ? 1 : 1LL << (64 - __builtin_clzll(n - 1)))
using namespace std;

int minOperationsToNonDecreasing(vector<int>& arr) {
    int operations = 0;
    int n = arr.size();
    
    if (n <= 1) return 0;
    map<int, int> extraPowers;
    map<int, int> closestPower2;

    closestPower2[arr[0]] = NEXT_POWER_OF_2(arr[0]);
    extraPowers[0] = 0;

    for(int i = 1; i < n; i++) {
        closestPower2[arr[i]] = NEXT_POWER_OF_2(arr[i]); 
        int power2Diff = closestPower2[arr[i-1]] - closestPower2[arr[i]];
        extraPowers[i] = max(0LL, extraPowers[i-1] + power2Diff);
        operations += max(0LL, power2Diff);  // Ensure only positive contributions

        // Debugging output (optional)
        cout << "Iteration " << i << ":\n";
        cout << "extraPowers: ";
        for (auto &p : extraPowers) {
            cout << "(" << p.first << ": " << p.second << ") ";
        }
        cout << "\n";
        
        cout << "closestPower2: ";
        for (auto &p : closestPower2) {
            cout << "(" << p.first << ": " << p.second << ") ";
        }
        cout << "\n";
    }

    return operations;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; 
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << "Total operations: " << minOperationsToNonDecreasing(arr) << endl;
    }
    return 0;
}
