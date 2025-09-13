#include "bits/stdc++.h"
using namespace std;

long long get_initial(int k, long long x)
{
    return x << k;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, x;
        cin >> k >> x;
        cout << get_initial(k, x) << endl;
    }
    return 0;
}