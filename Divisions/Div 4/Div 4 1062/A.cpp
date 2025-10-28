#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((a == b) && (b == c) && (c == d))
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }

        t -= 1;
    }

    return 0;
}