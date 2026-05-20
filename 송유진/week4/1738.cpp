#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = -1e15;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    vector<vector<int>> rev_adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({ u, v, w });
        rev_adj[v].push_back(u);
    }

    vector<bool> can_reach(n + 1, false);
    queue<int> q;
    q.push(n);
    can_reach[n] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : rev_adj[curr]) {
            if (!can_reach[next]) {
                can_reach[next] = true;
                q.push(next);
            }
        }
    }

    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, 0);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (const auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    bool has_cycle = false;
    for (const auto& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w > dist[e.v]) {
            if (can_reach[e.v]) {
                has_cycle = true;
                break;
            }
        }
    }

    if (has_cycle || dist[n] == INF) {
        cout << "-1\n";
    }
    else {
        vector<int> path;
        int curr = n;
        while (curr != 0) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}