#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    long long size = 1LL << n;
    vector<long long> s(size);
    for (long long i = 0; i < size; i++)
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    multiset<long long> S;
    for (long long x : s)
        S.insert(x);

    // Remove the empty subset sum (0)
    auto it0 = S.find(0);
    if (it0 != S.end())
        S.erase(it0);

    vector<long long> ans;
    ans.reserve(n);

    // Subset sums we can form with the elements in ans so far
    vector<long long> current_sums;
    current_sums.push_back(0); // sum of empty subset

    for (int i = 0; i < n; i++)
    {
        // The smallest remaining sum must be the next element
        long long x = *S.begin();
        ans.push_back(x);

        // Generate all new subset sums formed by adding x
        vector<long long> new_sums;
        new_sums.reserve(current_sums.size());
        for (long long v : current_sums)
        {
            new_sums.push_back(v + x);
        }

        // Remove those new sums from S (one occurrence each)
        for (long long val : new_sums)
        {
            auto it = S.find(val);
            if (it == S.end())
            {
                // Should not happen if input is valid
                // but we won't crash; just break.
                break;
            }
            S.erase(it);
        }

        // Add them to our known sums
        current_sums.insert(current_sums.end(), new_sums.begin(), new_sums.end());
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
