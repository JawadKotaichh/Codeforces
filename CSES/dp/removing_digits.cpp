/*

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> get_digits(int n)
{
    vector<int> digits;
    while (n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}
int main()
{

    int n;
    cin >> n;
    long long MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    int x = n;
    while (n != 0)
    {
        vector<int> digits = get_digits(n);
        // cout << "N = " << n << endl;
        int max_d = *max_element(digits.begin(), digits.end());
        // cout << "max_D = " << max_d << endl;

        dp[n - max_d] += 1;
        n -= max_d;
    }
    long long sumi = 0;
    for (int j = 1; j <= x; j++)
    {
        sumi += dp[j];
    }
    cout << sumi << endl;
    // for (int i = 1; i <= x; i++)
    // {
    //     cout << "dp[" << i << "] = " << dp[i] << endl;
    // }
}