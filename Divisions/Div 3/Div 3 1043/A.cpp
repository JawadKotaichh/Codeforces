#include <bits/stdc++.h>
using namespace std;
/*
    2 Strings a and b
    vlad can add characters of b to the beginning of the word
    and dima to the end of it


*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        string a;
        cin >> a;
        cin >> m;
        string b;
        cin >> b;
        string order;
        cin >> order;
        string dima;
        string vlad;
        for (int i = 0; i < order.size(); i++)
        {
            if (order[i] == 'D')
            {
                a += b[i];
            }
            else
            {
                a = b[i] + a;
            }
        }
        cout << a << endl;
    }

    return 0;
}