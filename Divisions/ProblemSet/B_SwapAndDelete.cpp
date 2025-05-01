#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int inf = 10000;

int main(){
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<int> c(m), d(m);
    vector<vector<int>> s(m);
    for(int i = 0; i < m; ++i){
        cin >> c[i] >> d[i];
        --d[i];
        for(int j = 0; j < c[i]; ++j){
            int x;
            cin >> x;
            s[i].push_back(x - 1);
        }
    }
    // buid adjacency list
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
        for(int& u: s[i])
            for(int& v: s[i])
                adj[u].push_back(v);
    // find distance
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for(int i = 0; i < n; ++i){
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int& v: adj[u])
                if(dist[i][v] == inf){
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
        }
    }
    // c[d][i][j] = min cost to travel from i to j using model d at least once
    // dp[s][j] = min cost to use all of s, and ending at 
    // n.2^k = 1e5
    // loop through model we're adding, 1e1
    // then inside, loop through start
    vector<vector<vector<int>>> cost(k, vector<vector<int>>(n, vector<int>(n, inf)));
    for(int i = 0; i < m; ++i){
        int type = d[i];
        for(int& u: s[i])
            for(int& v: s[i])
                cost[type][u][v] = min(cost[type][u][v], u == v ? 2 : 1);
        for(int& u: s[i])
            for(int& v: s[i])
                if(u != v){
                    for(int x = 0; x < n; ++x)
                        for(int y = 0; y < n; ++y)
                            cost[type][x][y] = min(cost[type][x][y], 1 + dist[u][x] + dist[v][y]);
                }
                else{
                    for(int x = 0; x < n; ++x)
                        for(int y = 0; y < n; ++y)
                            cost[type][x][y] = min(cost[type][x][y], 2 + dist[u][x] + dist[v][y]);
                }
    }
    vector<vector<int>> dp(1 << k, vector<int>(n, inf));
    dp[0][0] = 0;
    for(int mask = 1; mask < 1 << k; ++mask){
        for(int end = 0; end < n; ++end){
            for(int model = 0; model < k; ++model)
                if((mask & (1 << model)) != 0){
                    int submask = mask ^ (1 << model);
                    for(int start = 0; start < n; ++start)
                        dp[mask][end] = min(dp[mask][end], dp[submask][start] + cost[model][start][end]);
                }
        }
    }
    int all = (1 << k) - 1;
    int answer = dp[all][0];
    for(int i = 1; i < n; ++i) answer = min(answer, dp[all][i] + dist[0][i]);
    cout << (answer <= t ? "Yes" : "No");
    return 0;
}