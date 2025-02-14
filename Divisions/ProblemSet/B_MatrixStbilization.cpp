#include <bits/stdc++.h>
#define forn(n,i) for(int i=0;i<n;i++)
using namespace std;

int getMaxNeighbor(const vector<vector<int>>& matrix, int i, int j) {
    int n = matrix.size();  
    int m = matrix[0].size(); 
    int maxNeighbor = INT_MIN; 

    if (j + 1 < m) maxNeighbor = max(maxNeighbor, matrix[i][j + 1]);
    if (j - 1 >= 0) maxNeighbor = max(maxNeighbor, matrix[i][j - 1]);
    if (i + 1 < n) maxNeighbor = max(maxNeighbor, matrix[i + 1][j]);
    if (i - 1 >= 0) maxNeighbor = max(maxNeighbor, matrix[i - 1][j]);

    return maxNeighbor;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    forn(n, i) {
        forn(m, j) cin >> a[i][j];
    }

    bool stabilized = false;
    do {
        stabilized = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int maxNeighbor = getMaxNeighbor(a, i, j);
                bool greater = true;

                if (j + 1 < m && a[i][j] <= a[i][j + 1]) greater = false;
                if (j - 1 >= 0 && a[i][j] <= a[i][j - 1]) greater = false;
                if (i + 1 < n && a[i][j] <= a[i + 1][j]) greater = false;
                if (i - 1 >= 0 && a[i][j] <= a[i - 1][j]) greater = false;

                if (greater) {
                    a[i][j] = maxNeighbor;
                    stabilized = true;
                }
            }
        }
    } while (stabilized);

    for (const auto& row : a) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl; 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
