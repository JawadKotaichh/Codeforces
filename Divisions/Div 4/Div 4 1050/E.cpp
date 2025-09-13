#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*

    a[l,r] subarray of a
    a[l,r] is awesome:
    k empty multisets numbered from 1 to k
    for a[i] in a:
        if l<=i<=r:
            multiset[1].add(a[i])
        else:
            add a[i] to any multiset he wants (multiset 1 also)

    a[l,r] is awesome if:
        for every a[j] in a[l,r] he wants all sets to contain the same nb of a[j]

    goal: number of awesome subarrays


    After taking the array to be tested if it is awesome x:

        In the remaining elements outside x:
            I need at least (k-1) occurences of each one of the elements inside x
            Let y denote the remaining nb of occurences of elemnts inside x
                y should be divisible by k

        for the elements that are not inside x:
            I need to have their nb of occurences to be divisible by k


*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> freq(n + 1, 0);
        for (int x : a)
            ++freq[x];

        bool ok = true;
        for (int v = 1; v <= n; ++v)
        {
            if (freq[v] % k != 0)
            {
                ok = false;
                break;
            }
        }
        if (ok == false)
        {
            cout << 0 << endl;
        }
        else
        {
            vector<int> cap(n + 1, 0);
            for (int v = 1; v <= n; ++v)
                cap[v] = freq[v] / k;

            ll nb_of_arrays = 0;
            int R = 0;
            vector<int> win(n + 1, 0);
            for (int L = 0; L < n; ++L)
            {
                while (R < n && win[a[R]] < cap[a[R]])
                {
                    ++win[a[R]];
                    ++R;
                }
                nb_of_arrays += (R - L);
                --win[a[L]];
            }
            cout << nb_of_arrays << endl;
        }
    }

    return 0;
}