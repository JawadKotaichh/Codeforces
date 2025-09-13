#include <bits/stdc++.h>
using namespace std;

static vector<long long> P;

void build_powers()
{
    if (!P.empty())
        return;
    P.push_back(1);
    while (P.back() <= 1000000000LL / 3)
        P.push_back(P.back() * 3);
}
long long getCost(int x)
{
    if (x == 0)
        return 3;
    long long px = P[x];
    return 3 * px + 1LL * x * (px / 3);
}

long long get_min_cost(long long n)
{
    build_powers();
    long long min_cost = 0;
    long long curr_nb_power = 0;
    for (int i = (int)P.size() - 1; i >= 0; i--)
    {
        // cout << "Power: " << i << endl;
        curr_nb_power = n / P[i];
        // cout << "curr nb power " << curr_nb_power << endl;
        if (curr_nb_power != 0)
        {
            // cout << "Current cost: " << curr_nb_power * curr_cost << endl;
            min_cost += curr_nb_power * getCost(i);
            n -= curr_nb_power * P[i];
            // cout << "new n: " << n << endl;
        }
    }
    return min_cost;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << get_min_cost(n) << endl;
    }
    return 0;
}