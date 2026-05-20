#include <bits/stdc++.h>
using namespace std;
#define INF 1e18

int N, M, W;
vector<pair<int, int>> graph[505];
long long dist[505];

bool bellmanford() {
    fill(dist, dist + 505, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            for (pair<int, int> p : graph[j]) {
                int start = j;
                int end_ = p.first;
                int val = p.second;

                if (dist[end_] > dist[start] + val) {
                    dist[end_] = dist[start] + val;
                    
                    if (i == N - 1) return true; 
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M >> W;
    
    for (int i = 1; i <= N; i++) graph[i].clear();
    
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 0; i < W; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, -w});
    }

    if (bellmanford()) cout << "YES\n";
    else cout << "NO\n";
    }

    return 0;
}