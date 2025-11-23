// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define DEBUG 1
struct Node {
    int dist;
    int id;
};
int N, M; // N: 노드 수, M: 간선 수
const int INF = 1e9;
// 인접 리스트: (다음 노드, 가중치)
vector<vector<pair<int, int>>> adj;
vector<int> dist;
void daikstra(pair<int, int> start) {

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist = vector<int> (N+1, INF);

    dist[start.second] = start.first;
    pq.push(start);

    while(!pq.empty()) {
        pair<int, int> current_node = pq.top();
        int d = current_node.first;
        int i = current_node.second;
        pq.pop();

        if (dist[i] < d) continue;

        for (auto next_node : adj[i]){
            int next = next_node.first;
            int weight = next_node.second;

            int nextDist = d + weight;
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}
int main() {
    if (DEBUG) {
        N=5, M=6;   
    } else {
        cin >> N >> M;
    }

    adj = vector<vector<pair<int, int>>>((N+1));
    if (DEBUG){
        adj[1].push_back({2, 2}); adj[2].push_back({1, 2}); // 1 2 2
        adj[1].push_back({3, 5}); adj[3].push_back({1, 5}); // 1 3 5
        adj[2].push_back({3, 1}); adj[3].push_back({2, 1}); // 2 3 1
        adj[2].push_back({4, 2}); adj[4].push_back({2, 2}); // 2 4 2
        adj[3].push_back({4, 3}); adj[4].push_back({3, 3}); // 3 4 3
        adj[4].push_back({5, 1}); adj[5].push_back({4, 1}); // 4 5 1
        // 출력: 0 2 3 4 5 
    } else {
        for (int i = 0; i < M; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w}); // 양방향 그래프
        }
    }

    daikstra({0, 1});

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
}
