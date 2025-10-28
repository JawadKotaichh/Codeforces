#include <bits/stdc++.h>
using namespace std;

/*
n toys in a row
we can swap two toys if they have diferent parity

*/

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        bool same_parity = false;
        int pair = 0;
        int imp = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                pair += 1;
            }
            else
            {
                imp += 1;
            }
        }
        if ((pair == n) || (imp == n))
        {
            for (int i = 0; i < n; i++)
                cout << v[i] << " ";
            cout << "\n";
        }
        else
        {
            if ((pair >= 1) && (imp >= 1))
            {
                sort(v.begin(), v.end());
                for (int i = 0; i < n; i++)
                    cout << v[i] << " ";
                cout << "\n";
            }
            else
            {
                for (int i = 0; i < n; i++)
                    cout << v[i] << " ";
                cout << "\n";
            }
        }
        t -= 1;
    }

    return 0;
}