#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {

        map<int, vector<int>> found;
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        vector<int> sorted_v(n);

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            v[i] = k;
            if (found.find(v[i]) != found.end())
            {
                found[v[i]].push_back(i);
            }
            else
            {
                found[v[i]] = {i};
            }
            sorted_v[i] = k;
        }
        bool possible = true;
        // cout << x << endl;

        // for (const auto &pair : found)
        // {
        //     cout << "value: " << pair.first << ", index: " << pair.second << endl;
        // }
        sort(sorted_v.begin(), sorted_v.end());
        for (int j = 0; j < sorted_v.size(); j++)
        {
            // cout << "sorted_v[j]= " << sorted_v[j] << endl;
            vector<int> vv = found[sorted_v[j]];
            for (int k = 0; k < vv.size(); k++)
            {
                if (abs(vv[k] - j) == x)
                {
                    vv[k] = -2 * 1000000;
                }
                if (abs(vv[k] - j) != x && abs(vv[k] - j) != 0)
                {
                    // cout << "found[sorted_v[j]] = " << found[sorted_v[j]] << endl;
                    // cout << "new index = " << j << endl;
                    // cout << "Diff = " << abs(found[sorted_v[j]] - j) << endl;
                    possible = false;
                    break;
                }
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        t -= 1;
    }

    return 0;
}