#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll horiz, vertical, x, y;
        cin >> horiz >> vertical >> x >> y;
        vector<ll> ys(horiz);
        vector<ll> xs(vertical);
        for (int i = 0; i < horiz; i++)
            cin >> ys[i];
        for (int j = 0; j < vertical; j++)
            cin >> xs[j];
        cout << vertical + horiz << endl;
    }

    return 0;
}