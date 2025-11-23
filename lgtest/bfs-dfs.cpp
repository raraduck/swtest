#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define DEBUG 1

struct Node {
    int idx;
    int val;
};
int N;
vector<int> Parents;
vector<int> Values;
vector<vector<Node>> Adj;
// int ret;
int bfs(Node node){
    deque<Node> dq;
    dq.push_back(node);
    int idx, val;
    while(dq.size()) {
        Node here = dq.front();
        idx = here.idx;
        val = here.val;
        dq.pop_front();

        // for (auto next_node : Adj[idx]){
        for (int i=Adj[idx].size()-1; i>=0; i--){
            Node next_node = Adj[idx][i];
            dq.push_back({next_node});
        }
    }
    return val;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (DEBUG) {
        
        // Case 1
        // N = 5;
        // Parents = {-1, 0, 0, 1, 1}; // 3 node
        // Values =  {5, 6, 7, 8, 9}; // 8

        // Case 2
        // N = 6;
        // Parents = {-1, 0, 0, 1, 2, 2}; // 3 node
        // Values =  {5, 6, 7, 8, 9, 10}; // 8

        // Case 3
        // N = 5;
        // Parents = {-1,0,1,2,3};
        // Values  = {5,6,7,8,9};
        // Tree:
        // 0 → 1 → 2 → 3 → 4
        // 왼쪽 말단 leaf = 4 → val = 9

        // Case 4
        N = 8;
        Parents = {-1,0,0,1,1,2,2,3};
        Values  = {5,6,7,8,9,10,11,12};
        // 왼쪽 말단 leaf = 7 → val = 12

        // Case 5
        // N = 4;
        // Parents = {-1,0,1,2};
        // Values  = {5,6,7,8};
        // 왼쪽 leaf가 없지만 “유일한 leaf” = 3 → val = 8
    }

    Node root = {0, -1};
    Adj = vector<vector<Node>>(N);
    for (int i=0; i<N; i++) {
        int val = Values[i];
        int origin = Parents[i];
        if (origin == -1) root = {i, val};
        else Adj[origin].push_back({i, val});
    }

    int ret = bfs(root);

    cout << ret;

    return 0;
}