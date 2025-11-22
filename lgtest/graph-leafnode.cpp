#include <iostream>
#include <vector>

using namespace std;
#define DEBUG 0

vector<vector<int>> mAdj;
int leafCount = 0;
void dfs(int node, int detach){
    if (node == detach) return;

    bool hasAliveChild = false;

    for(auto from : mAdj[node]) {
        if (from == detach) continue;
        hasAliveChild = true;
        dfs(from, detach);
    }
    if (hasAliveChild == false) {
        leafCount++;
    }
}

int main() {
    int N; // 노드의 개수 (1:51)
    vector<int> Parents;
    int Detach;

    if (DEBUG) {
        N = 5;
        Parents = {-1, 0, 0, 1, 1};
        Detach = 2;
    } else {
        cin >> N;
        Parents = vector<int>(N,0);
        for (int i=0; i<N; i++){
            cin >> Parents[i];
        }
        cin >> Detach;
    }

    // dfs (완전탐색) 로 하면서 backtracking (=detach 노드는 탐색하지 않기)
    // leaf node 조건인 경우만 cnt+1 하면 될듯

    mAdj = vector<vector<int>> (N);
    // Visited = vector<int>(N,0);
    int root;
    
    for (int node=0; node<Parents.size(); node++){
        if (Parents[node] == -1) root = node;
        else {
            int from = Parents[node];
            mAdj[from].push_back(node);
        }
    }

    dfs(root, Detach);

    cout << leafCount << "\n";

    return 0;
}