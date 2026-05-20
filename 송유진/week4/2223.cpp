#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, w;
};

void solve() {
    int N, M, B;
    cin >> N >> M >> B;

    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ u, v, w });
        edges.push_back({ v, u, w });
    }

    for (int i = 0; i < B; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ u, v, -w });
    }

    vector<int> dist(N + 1, 0);
    bool hasNegativeCycle = false;

    for (int i = 1; i <= N; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                if (i == N) {
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

    int F;
    if (cin >> F) {
        while (F--) {
            solve();
        }
    }

    return 0;
}