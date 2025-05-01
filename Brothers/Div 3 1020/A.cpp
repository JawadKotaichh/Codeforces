#include <bits/stdc++.h>
using namespace std;

int count_ones(string s)
{
    int count = 0;
    int count_ones_orig = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            count_ones_orig += 1;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            count += count_ones_orig - 1;
        else
            count += count_ones_orig + 1;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        string s;
        cin >> s;
        cout << count_ones(s) << endl;
    }
    return 0;
}