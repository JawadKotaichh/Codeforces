#include<bits/stdc++.h>
#define forn(n, i) for (int i = 0; i < n; i++)
#define v vector
using namespace std;

int OverAllScore(int n, int k, vector<int>& numbers) {
    sort(numbers.begin(), numbers.end());  
    int score = 0;
    
    unordered_map<int, int> freq;
    for (int num : numbers) {
        freq[num]++;
    }

    for (int num : numbers) {
        if (freq[num] > 0) {
            int complement = k - num;
            
            if (freq[complement] > 0) {
                if (num == complement && freq[num] > 1) {
                    score++;
                    freq[num] -= 2;
                } else if (num != complement && freq[complement] > 0) {
                    score++;
                    freq[num]--;
                    freq[complement]--;
                }
            }
        }
    }

    return score;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        forn(n,i) cin >> a[i];
        cout << OverAllScore(n, k, a) << endl;
    }
    return 0;
}
