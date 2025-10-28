#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    long long t;
    cin >> t;
    const int primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    while (t != 0)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
            cin >> v[i];
        long long g = 0;
        for (int i = 0; i < n; ++i)
        {
            g = gcd(g, v[i]);
        }

        long long ans = -1;
        for (int p : primes)
        {
            if (g % p != 0)
            {
                ans = p;
                break;
            }
        }
        cout << ans << "\n";

        t -= 1;
    }

    return 0;
}