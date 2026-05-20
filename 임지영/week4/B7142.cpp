
// 백준 7142 데이터 만들기 3


#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    // 정점 50개, 간선 49개 출력
    cout << 50 << ' ' << 49 << '\n';
    
    // 50번부터 1번까지 역순으로 이어지는 일직선 그래프 생성
    // 49 -> 50, 48 -> 49, ..., 1 -> 2 형식으로 -1 가중치를 줌
    for(int i = 49; i > 0; i--) {
        cout << i << ' ' << i + 1 << ' ' << -1 << '\n';
    }
    return 0;
}