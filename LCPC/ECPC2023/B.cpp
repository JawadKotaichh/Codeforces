/*
    subsequence of a string is Mythical if no two consecutive
    letters in the sub-sequence are equal
    abaabc
    -> ababc
    -> ababc
    abc
    ->abc
    acccaa
    -> aca
    -> aca
    -> aca
    ->
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long mod = 1e9 + 7;
    while (t--)
    {
        string s;
        cin >> s;
        int largest_len = 0;
        int count = 1;
        long long ways = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                count += 1;
            }
            else
            {
                largest_len += 1;
                ways = (ways * count) % mod;
                count = 1;
            }
        }
        largest_len += 1;
        ways = (ways * count) % mod;

        cout << largest_len << " " << ways << endl;
    }

    return 0;
}