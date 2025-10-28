#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a1;
        int a2;
        int a3;
        int a4;
        int a;
        int b;
        int val_1;
        int val_2;
        cin >> a >> val_1;
        cin >> b >> val_2;
        int a5;
        if (a == 1)
        {
            a1 = val_1;
            a2 = 90 - a1;
            a5 = a2;
        }
        else
        {
            a2 = val_1;
            a1 = 90 - a2;
            a5 = a2;
        }
        if (a == 3)
        {
            a3 = val_2;
            a4 = 180 - a3 - a5;
        }
        else
        {
            a4 = val_2;
            a3 = 180 - a4 - a5;
        }
        if (a1 + a2 + 90 == 180 && a1 > 0 && a2 > 0 && a3 + a4 + a5 == 180 && a3 > 0 && a4 > 0 && a5 > 0)
        {
            cout << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}