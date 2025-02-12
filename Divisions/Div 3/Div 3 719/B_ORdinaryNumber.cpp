#include <bits/stdc++.h>
using namespace std;

void countOrdinaryNumbers(vector<int> testCases) {
    for (int n : testCases) {
        int count = 0;

        for (int d = 1; d <= 9; d++) { 
            long long num = d;
            while (num <= n) {
                count++;
                num = num * 10 + d; 
            }
        }

        cout << count << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    vector<int> testCases(t);
    for (int i = 0; i < t; i++) {
        cin >> testCases[i];
    }

    countOrdinaryNumbers(testCases);

    return 0;
}
