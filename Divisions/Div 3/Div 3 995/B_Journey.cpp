#include<bits/stdc++.h>
#define forn(n, i) for (int i = 0; i < n; i++)
#define v vector
using namespace std;

/*
    He would walk a km on the first day,
    b km on the second day,
    c km on the third day,
    on the fourth as the first, and so on.
    Monocarp will complete his journey after he walks at least n km.
*/

int Day(int n, int a, int b, int c) {
    int cycle_sum = a + b + c;
    int cycles = n / cycle_sum;
    int sum = cycles * cycle_sum;
    int count = cycles * 3; 

    int remaining = n - sum;

    if (remaining > 0) {
        count++;
        remaining -= a;
    }
    if (remaining > 0) {
        count++;
        remaining -= b;
    }
    if (remaining > 0) {
        count++;
        remaining -= c;
    }

    return count;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        cout << Day(n, a, b, c) << endl;
    }
    return 0;
}
