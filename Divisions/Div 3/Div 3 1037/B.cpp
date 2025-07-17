#include <bits/stdc++.h>
using namespace std;

/*
    arr a and number k
    a[i] weather at day i
    a[i]=1 it rains
    a[i]=0 it is good on
    it takes him k days to do one hike, the weather must be good
    after one hike a break of one day
    max number of peaks
*/

int getMaxPossible(vector<int> a, int n, int k)
{
    int answer = 0;
    int i = 1;
    int consecutiveZeros = 0;
    vector<int> countOfConsecutiveZeros;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            consecutiveZeros += 1;
        }
        else
        {
            if (consecutiveZeros >= k)
            {
                while (consecutiveZeros >= k)
                {
                    consecutiveZeros -= k;
                    answer += 1;
                    consecutiveZeros -= 1;
                }
            }
            consecutiveZeros = 0;
        }
    }

    if (consecutiveZeros >= k)
    {
        while (consecutiveZeros >= k)
        {
            consecutiveZeros -= k;
            answer += 1;
            consecutiveZeros -= 1;
        }
    }

    return answer;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << getMaxPossible(a, n, k) << endl;
    }
    return 0;
}