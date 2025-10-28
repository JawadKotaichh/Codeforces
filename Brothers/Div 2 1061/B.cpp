#include <bits/stdc++.h>
using namespace std;
// int i
// >=4j j 2j 3j

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n, q;
        cin >> n >> q;
        vector<char> gates(n);
        vector<int> inputt(q);

        for (int k = 0; k < n; k++)
        {
            cin >> gates[k];
        }
        for (int k = 0; k < q; k++)
        {
            cin >> inputt[k];
        }
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (gates[j] == 'A')
            {
                c += 1;
            }
        }

        if (c == q)
        {
            for (int k = 0; k < q; k++)
            {
                cout << inputt[k] << "\n";
            }
        }
        else
        {
            for (int k = 0; k < q; k++)
            {
                // cout << "hi" << inputt[k] << endl;
                int curr = inputt[k];
                int i = 0;
                int count = 0;
                while (curr != 0)
                {
                    if (gates[i] == 'A')
                    {
                        curr -= 1;
                    }
                    else
                    {
                        curr = curr / 2;
                        // cout << "curr = " << curr << endl;
                    }

                    if (i == n - 1)
                    {
                        i = 0;
                    }
                    else
                    {
                        i += 1;
                    }
                    count += 1;
                }
                cout << count << "\n";
            }
        }

        t -= 1;
    }
    return 0;
}