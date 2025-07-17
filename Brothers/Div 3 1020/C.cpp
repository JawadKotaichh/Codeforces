#include <bits/stdc++.h>
using namespace std;

int cherry(vector<int> a, vector<int> b, int n, int k)
{
    bool isAlreadyNotCompliment = false;
    int commun_sum = -1;

    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1 && commun_sum == -1)
        {
            commun_sum = b[i] + a[i];
        }
        if (b[i] != -1 && commun_sum != -1)
        {
            if (b[i] + a[i] != commun_sum)
            {
                isAlreadyNotCompliment = true;
                break;
            }
        }
    }

    if (isAlreadyNotCompliment)
        return 0;
    else
    {
        if (commun_sum != -1)
        {
            int mini = *min_element(a.begin(), a.end());
            int maxi = *max_element(a.begin(), a.end());
            if (commun_sum >= maxi && commun_sum <= k + mini)
            {
                return 1;
            }
            else
                return 0;
        }
        else
        {
            int mini = *min_element(a.begin(), a.end());
            int maxi = *max_element(a.begin(), a.end());
            int max_possible_sum = mini + k;
            return max_possible_sum - maxi + 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }

        cout << cherry(a, b, n, k) << endl;
    }
    return 0;
}