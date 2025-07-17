#include <bits/stdc++.h>
using namespace std;

bool Possible(vector<int> heights, int n, int k)
{
    bool answer = false;
    int currentTower = heights[k - 1];
    int waterLevel = 1;
    int max_height = *max_element(heights.begin(), heights.end());
    if (heights[k - 1] == max_height)
    {
        return true;
    }
    vector<int> candidates;

    for (int h : heights)
    {
        if (h > currentTower)
        {
            candidates.push_back(h);
        }
    }
    sort(candidates.begin(), candidates.end());

    for (int i = 0; i < candidates.size(); i++)
    {
        int time_needed = candidates[i] - currentTower;
        if (waterLevel + time_needed > currentTower + 1)
        {
            return false;
        }
        waterLevel += time_needed;
        currentTower = candidates[i];
        if (max_height == currentTower)
        {
            answer = true;
            break;
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
        if (Possible(a, n, k))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}