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

pair<long long, vector<pair<long long, long long>>> get_min_number_of_deals(long long n)
{
    long long min_cost = 0;
    long long curr_nb_power = 0;
    long long required_nb_of_deals = 0;
    vector<pair<long long, long long>> powers_required;

    for (int i = (int)P.size() - 1; i >= 0; i--)
    {
        curr_nb_power = n / P[i];
        if (curr_nb_power != 0)
        {
            long long before_cost = min_cost;
            long long take_cost = curr_nb_power * getCost(i);
            min_cost += take_cost;
            n -= curr_nb_power * P[i];
            required_nb_of_deals += curr_nb_power;

            powers_required.push_back({curr_nb_power, i});
        }
    }

    return {min_cost, powers_required};
}

long long get_min_cost(long long n, long long k)
{
    build_powers();
    auto base = get_min_number_of_deals(n);
    long long cost = base.first;

    long long deals = 0;
    for (auto &pr : base.second)
        deals += pr.first;

    long long rem = k - deals;
    if (rem < 0)
        return -1;
    priority_queue<pair<int, long long>> pq;
    for (auto &pr : base.second)
        if (pr.first > 0 && pr.second > 0)
            pq.push({(int)pr.second, pr.first});

    while (rem >= 2 && !pq.empty())
    {
        auto [p, c] = pq.top();
        pq.pop();
        if (p == 0)
            break;

        long long can = min(c, rem / 2);
        if (can == 0)
            continue;
        long long delta = 3 * getCost(p - 1) - getCost(p);
        cost += can * delta;
        rem -= 2 * can;

        long long leftover = c - can;
        if (leftover > 0)
            pq.push({p, leftover});
        pq.push({p - 1, 3 * can});
    }
    return cost;
    // // {{count: 2, power: 2},{count: 1, power: 1},{count: 1, power: 0}}=>n=18+3+1= 22
    // // remaining:5
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << get_min_cost(n, k) << endl;
    }
    return 0;
}
