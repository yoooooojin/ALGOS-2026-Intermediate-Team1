#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, w;
};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({ u, v, weight });
        edges.push_back({ v, u, weight });
    }

    for (int i = 0; i < w; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({ u, v, -weight });
    }

    vector<int> dist(n + 1, 0);
    bool hasNegativeCycle = false;

    for (int i = 1; i <= n; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                if (i == n) {
                    hasNegativeCycle = true;
                }
            }
        }
    }

    if (hasNegativeCycle) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    if (cin >> tc) {
        while (tc--) {
            solve();
        }
    }

    return 0;
}