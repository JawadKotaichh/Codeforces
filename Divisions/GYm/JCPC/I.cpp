#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int countTriangleFreeSubsequences(vector<int> &vec)
{
    int n = vec.size();
    sort(vec.begin(), vec.end()); // Sort the array to easily check triangle condition

    long long count = 0; // To count valid subsequences

    // Count subsequences of length 1 and 2
    count = (count + n + (n * (n - 1)) / 2) % MOD;

    // Count subsequences of length 3
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                // Check if the subsequence (vec[i], vec[j], vec[k]) forms a triangle
                if (vec[i] + vec[j] > vec[k])
                {
                    count = (count + 1) % MOD;
                }
            }
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    cout << countTriangleFreeSubsequences(vec) << endl;
    return 0;
}
