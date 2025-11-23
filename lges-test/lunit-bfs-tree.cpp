#include <iostream>
#include <deque>

using namespace std;

#define DEBUG 1

struct node {
    int id;
    int val;
};

int N = 5;
vector<int> Parents;
vector<int> Values;
vector<vector<node>> Adj;
int ret = 0;

void bfs(deque<node>& q){
    while(q.size()){
        node here = q.front();
        ret = here.val;
        q.pop_front();
        // for (auto to : Adj[from.id]){
        for (int i=Adj[here.id].size()-1; i>=0; i--){
            node there = Adj[here.id][i];
            q.push_back(there);
        }
    }
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
        // N = 8;
        // Parents = {-1,0,0,1,1,2,2,3};
        // Values  = {5,6,7,8,9,10,11,12};
        // 왼쪽 말단 leaf = 7 → val = 12

        // Case 5
        N = 4;
        Parents = {-1,0,1,2};
        Values  = {5,6,7,8};
        // 왼쪽 leaf가 없지만 “유일한 leaf” = 3 → val = 8
    }

    Adj = vector<vector<node>>(N);

    node root = {0, 0};
    for (int i=0; i<N; i++) {
        if (Parents[i] == -1) root = {i, Values[i]};
        else {
            int from = Parents[i];
            int val = Values[i];
            Adj[from].push_back({i, val});
        }
    }

    deque<node> Q;
    Q.push_back(root);

    bfs(Q);

    cout << ret;

    return 0;
}