#include <bits/stdc++.h>
using namespace std;


/*
    We have a tree of n vertices with root 1
    The tree is connected graph without loops and multiple edges
    If the apple is at vertex u
    If u has a child, the apple moves to it
    Else it falls from the tree

    We always have two apples and we are give q assumptions
    Each asumption is the vertice of each apple

    Our goal is to count the number of possible pairs where the apples go out
    The answer is the number of possible ways to get out for the first times the number of possible ways for the second
    And to get the number of possible ways to get out for each apple using dfs
    And the answer is their multiplication
*/


const int MAXN = 200005;

vector<int> tree[MAXN];
int parent[MAXN];

void dfs(int node, int par) {
    parent[node] = par;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
}

vector<int> getFallingPoints(int node) {
    vector<int> fallingPoints;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (tree[cur].size() == 1 && cur != 1) {
            fallingPoints.push_back(cur);
        }
        for (int child : tree[cur]) {
            if (child != parent[cur]) {
                q.push(child);
            }
        }
    }
    return fallingPoints;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs(1, -1);

        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;

            vector<int> fallingPointsX = getFallingPoints(x);
            vector<int> fallingPointsY = getFallingPoints(y);

            int result = fallingPointsX.size() * fallingPointsY.size();
            cout << result << '\n';
        }
    }

    return 0;
}

