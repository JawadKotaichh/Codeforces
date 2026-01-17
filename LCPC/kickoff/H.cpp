#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

void topDFS(ll node, vector<vector<ll>> &graph, vector<bool> &visited, vector<ll> &topSorted)
{
    visited[node] = true;
    for (ll next : graph[node])
        if (!visited[next])
            topDFS(next, graph, visited, topSorted);
    topSorted.push_back(node);
}

void TOP(vector<vector<ll>> &G, vector<ll> &topOrder)
{
    vector<bool> visited(G.size(), false);
    for (ll i = 0; i < G.size(); ++i)
    {
        if (!visited[i])
            topDFS(i, G, visited, topOrder);
    }
}

void DFS_func(ll node, vector<vector<ll>> &graph, vector<bool> &visited, vector<ll> &startTime, vector<ll> &endTime, ll &time)
{
    visited[node] = true;
    startTime[node] = time;
    time++;
    for (ll neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            DFS_func(neighbor, graph, visited, startTime, endTime, time);
        }
    }
    endTime[node] = time;
    time++;
}

void DFS(vector<vector<ll>> &G, vector<ll> &startTime, vector<ll> &endTime)
{
    vector<bool> visited(G.size(), false);
    ll time = 0;

    for (ll i = 0; i < G.size(); ++i)
    {
        if (!visited[i])
            DFS_func(i, G, visited, startTime, endTime, time);
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> test = {};
    vector<vector<ll>> G(n, test);
    vector<ll> startTime(n, 0);
    vector<ll> endTime(n, 0);
    vector<ll> a;
    for (ll i = 0; i < n; ++i)
    {
        ll s;
        cin >> s;
        a.push_back(s);
    }
    vector<ll> b;
    for (ll i = 0; i < n; ++i)
    {
        ll s;
        cin >> s;
        b.push_back(s);
    }

    for (ll i = 0; i < n - 1; ++i)
    {
        ll u;
        ll v;
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        if (v == 1)
        {
            G[v - 1].push_back(u - 1);
        }
    }

    vector<vector<ll>> W(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < n; ++j)
        {
            W[i][j] = a[i] * b[j];
        }
    }

    DFS(G, startTime, endTime);
    vector<ll> top_ord = {};
    TOP(G, top_ord);

    vector<ll> dp(G.size(), 1e12);
    // for (ll i = 0; i < n; ++i)
    // {
    //     if (G[i].size() == 0)
    //     {
    //         dp[i] = 0;
    //         cout << "i = " << i << " is a leaf" << endl;
    //     }
    // }
    // cout << "Start" << endl;
    // for (ll i = 0; i < n; ++i)
    // {
    //     cout << startTime[i] << " ";
    // }
    // cout << endl;
    // cout << "END" << endl;

    // for (ll i = 0; i < n; ++i)
    // {
    //     cout << endTime[i] << " ";
    // }
    // cout << endl;
    for (ll k = 0; k < top_ord.size(); ++k)
    {
        ll i = top_ord[k];
        bool havechild = false;
        for (ll j = 0; j < G.size(); j++)
        {
            if (startTime[i] < startTime[j] && endTime[j] < endTime[i])
            {
                dp[i] = min(dp[j] + W[i][j], dp[i]);
                havechild = true;
            }
        }
        // cout << "i = " << i << " have a child: " << havechild << endl;
        if (!havechild)
        {
            dp[i] = 0;
        }
    }
    // cout << "OLD" << endl;

    // for (ll i = 0; i < n; ++i)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    for (ll k = 0; k < top_ord.size(); ++k)
    {
        ll i = top_ord[k];
        for (ll j = 0; j < G.size(); j++)
        {
            if (startTime[i] < startTime[j] && endTime[j] < endTime[i])
            {
                dp[i] = min(dp[j] + W[i][j], dp[i]);
            }
        }
    }
    // cout << "NEW" << endl;
    // for (ll i = 0; i < n; ++i)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    // for(ll j = 0 ; j < G.size() ; j++){
    //     if(startTime[top_ord[0]] < startTime[j] && endTime[j] < endTime[top_ord[n-1]]){
    //         dp[top_ord[0]] = min(dp[j] + W[top_ord[0]][j], dp[top_ord[0]]);
    //     }
    // }

    for (ll i = 0; i < n; ++i)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";

    return 0;
}
