#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int N,M;
vector<pair<int,int>>graph[101];
long long dist[101]; // dist[u]는 1->u까지 가는 경로중 최단 경
int before[101]; // before[v]=u이면 최단경로상 u->v 간선을 지나감을 의미

void bellmanford(){
    fill(dist,dist+101,INF);
    dist[1]=0;
    for(int i=0;i<N;i++){
        for(int j=1;j<N+1;j++){
            for(pair <int,int>p : graph[j]){
                int start=j;
                int end_=p.first;
                int val=p.second;
                if(dist[start]!=INF &&dist[end]>dist[start]+val){
                    dist[end_] = dist[start] + val;
                    before[end_]=start;
                    // N번째 회차에도 값이 갱신된다면 음수 사이클 존재
                    if(i==N-1)dist[end_]=-INF;
                }
            }
        }
    }
    //도달할 수 없거나 음수사이클
    if(dist[N]==INF || dist[N]==-INF)cout<<"-1";
    else{
        vector<int>path;
        int s=N;
        while(s!=0){
            path.push_back(s);
            s=before[s];
            for(int i=path.size()-1;i>=0;i--)cout<<path[i]<<" ";
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    bellmanford();

    return 0;
}