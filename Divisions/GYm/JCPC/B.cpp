#include <bits/stdc++.h>
using namespace std;

void generate_cyclic_shifts()
{
    int len = target.length();
    for (int i = 0; i < len; ++i)
    {
        string shift = target.substr(i) + target.substr(0, i);
        cyclic_shifts.push_back(shift);
    }
}

int Count(vector<vector<char>> grid, string target, int r, int c)
{
    int answer = 0;
};

int main()
{
    const int MOD = 998244353;
    const string target = "genshinimpact";
    vector<string> cyclic_shifts;

    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> inputArray(r, vector<char>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> inputArray[i][j];
            }
        }
        cout << Count(inputArray, target, r, c) << endl;
    }
    return 0;
}
