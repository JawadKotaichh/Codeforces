#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    1 min to go to other side of the gym
    if yes +1 point
    Fj run the pacer test until m-th minute
    0 -> side
    1 -> other side
    after the a[i]-th minute FJ must be at the b[i] side of the gym

    the audio plays n time

    max number of pts FJ can acquire

*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll m;
        cin >> n >> m;

        vector<pair<ll, int>> pairs(n);
        for (int i = 0; i < n; ++i)
        {
            ll a;
            int b;
            cin >> a >> b;
            pairs[i] = {a, b};
        }
        ll score = 0;
        int curr = 0;
        ll prev_time = 0;
        for (int j = 0; j < n; j++)
        {
            pair<ll, int> p = pairs[j];
            ll s = p.first - prev_time;
            int pos = p.second;
            if (pos == curr)
            {
                if (s % 2 == 0)
                {
                    score += s;
                }
                else
                {
                    score += (s - 1);
                }
            }
            else
            {
                if (s % 2 != 0)
                {
                    score += s;
                }
                else
                {
                    score += (s - 1);
                }
            }
            curr = pos;
            prev_time = p.first;
        }
        if (m > prev_time)
        {
            score += m - prev_time;
        }
        cout << score << endl;
    }

    return 0;
}