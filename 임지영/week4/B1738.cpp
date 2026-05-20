
// 백준 1738 골목길 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define INF 100000000
using namespace std;

// typedef로 가독성 높임
typedef pair<int, int> pii;

int n, m, dist[501], parent[501];
vector <pair<pii, int>>edge;
vector<int> edge_bfs[501];
bool flag = false;
bool visited[501];

void bellmanFord() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int from = edge[j].first.first;
			int to = edge[j].first.second;
			int weight = edge[j].second;

			if (dist[from] == INF) continue;

			if (dist[to] > dist[from] + weight) {
				dist[to] = dist[from] + weight;
				parent[to] = from;
			}
		}
	}

	for (int j = 0; j < edge.size(); j++) {
		int from = edge[j].first.first;
		int to = edge[j].first.second;
		int weight = edge[j].second;

		if (dist[from] == INF) continue;

		//음의 사이클 발생
		if (dist[to] > dist[from] + weight) {
			//bfs로 해당 지점에서 n에 도달 가능한지 체크
			queue<int> q;
			q.push(to);
			visited[to] = true;
			while (!q.empty()) {
				int tmp = q.front();
				q.pop();
				for (int i = 0; i < edge_bfs[tmp].size(); i++) {
					int next = edge_bfs[tmp][i];
					if (next == n) {
						flag = true;
						return;
					}
					if (!visited[next]) {
						visited[next] = true;
						q.push(next);
					}
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		parent[i] = -1;
		visited[i] = false;
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({ {u, v}, -w });
		edge_bfs[u].push_back(v);
	}

	dist[1] = 0;

	bellmanFord();

	if (flag || dist[n] == INF) {
		cout << -1;
		return 0;
	}

	stack<int> s;
	int to = n;
	while (to != -1) {
		s.push(to);
		to = parent[to];
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}