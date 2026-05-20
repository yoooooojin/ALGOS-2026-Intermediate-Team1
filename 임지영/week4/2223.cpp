
// 정올 2223 블랙홀

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999
#define MAX 2501
using namespace std;

vector<pair<int, int>> graph[MAX];
long long dist[MAX]; // 갱신된 거리 저장용

int N, M, B; 

bool bellman_ford(int start){
    // 거리 배열 초기화
    for(int i=1; i<=N; i++){
        dist[i] = INF;
    }


    dist[start] = 0; // 시작점의 거리는 0

    // 모든 간선을 확인하며 거리 갱신
    for(int i=1; i<=N; i++){
        // 모든 from 노드 확인
        for(int from=1; from<= N; from++)

            // from 노드에서 갈 수 있는 모든 to 노드 확인
            for(int pos = 0; pos<graph[from].size(); pos++){
                int to = graph[from][pos].first; // 도착 노드
                int weight = graph[from][pos].second; // 간선 가중치

                if (dist[to] > dist[from] + weight) {
                    if (i == N) return true; // N번째 루프인데도 갱신이 된다면 음수 사이클 존재!
                    dist[to] = dist[from] + weight;
                }
            }
        }

        return false;
    }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int F; cin >> F;

    while(F-->0){
        cin >> N >> M >> B;
        
        // 그래프 초기화
        for(int i = 1; i <= N; i++) {
            graph[i].clear();
        }

        for(int i=0; i<M; i++){
            int S, E, T; cin >> S >> E >> T;
            // 양방향 그래프
            graph[S].push_back({E, T});
            graph[E].push_back({S, T});
        }

        // 웜홀 정보
        for(int i=0; i<B; i++){
            int S, E, T; cin >> S >> E >> T;
            // 단방향 그래프
            graph[S].push_back({E, -T});
        }

        if (bellman_ford(1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}