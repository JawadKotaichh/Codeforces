#include "bits/stdc++.h"
using namespace std;

#include "bits/stdc++.h"
using namespace std;

long long get_max_even(long long a, long long b)
{
    if (a % 2 == 1 && b % 2 == 0)
    {
        b /= 2;
        a *= 2;
    }
    if (b % 2 == 1 && a % 2 == 0)
    {
        return -1;
    }
    if (b % 2 == 0)
    {
        a *= b;
        a /= 2;
        b = 2;
    }
    else
    {
        a *= b;
        b = 1;
    }
    return a + b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        cout << get_max_even(a, b) << "\n";
    }
    return 0;
}