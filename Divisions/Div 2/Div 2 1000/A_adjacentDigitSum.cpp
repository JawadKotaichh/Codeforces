#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (y > x + 1 or x == y)
            cout << "NO" << endl;
        else if (y == x + 1)
            cout << "YES" << endl;
        else
        {
            bool found = false;

            while (x >= 0)
            {

                x -= 9;
                if (x + 1 == y)
                {
                    found = true;
                    cout << "YES" << endl;
                }
            }
            if (found == false)
                cout << "NO" << endl;
        }
    }
}