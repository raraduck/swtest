// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define DEBUG 1

const int INF = 1e9;

int main() {
    int N, M; // N: 노드 수, M: 간선 수
    if (DEBUG) {
        N=5, M=6;   
    } else {
        cin >> N >> M;
    }

    // 인접 리스트: (다음 노드, 가중치)
    vector<vector<pair<int,int>>> adj(N+1);

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

    // 거리 배열
    vector<int> dist(N+1, INF);

    // 우선순위 큐 (거리, 노드)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // 시작 노드: 1번
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, here] = pq.top();
        pq.pop();

        // 이미 더 짧은 경로를 알고 있다면 건너뛰기
        if (dist[here] < cost) continue;

        // 주변 노드 탐색
        for (auto &edge : adj[here]) {
            int next = edge.first;
            int weight = edge.second;

            int nextDist = cost + weight;

            // 더 짧게 갈 수 있으면 갱신
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
}
