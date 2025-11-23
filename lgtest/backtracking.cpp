#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1

int N;
vector<int> Parents;
int Detach;
vector<vector<int>> Adj;
int leafCount=0;
void dfs(int node) {
    if (node == Detach) return;

    if (Adj[node].size()==0) {
        leafCount += 1;
        return;
    }

    bool hasAliveChild = false;

    for (auto next_node : Adj[node]){
        if (next_node == Detach) continue;
        hasAliveChild = true;
        dfs(next_node);
    }

    if (hasAliveChild == false) leafCount += 1;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (DEBUG){
        N = 5;
        Parents = {-1, 0, 0, 1, 1};
        // Detach = 2; // 2
        // Detach = 1; // 1
        Detach = 0; // 0
    }

    int root;
    Adj = vector<vector<int>>(N);
    for (int i=0; i<N; i++){
        int orig = Parents[i];
        if (orig == -1) root = i;
        else Adj[orig].push_back(i);
    }

    dfs(root);

    cout << leafCount << "\n";
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // permu
// vector<int> Arr;
// void permu(int n, int r, int depth) {
//     if (depth == r) {
//         for (int i=0; i<r; i++){
//             cout << Arr[i] << " ";
//         }
//         cout << "\n";
//         return;
//     }
//     for(int i=depth; i<n; i++){
//         swap(Arr[depth], Arr[i]);
//         permu(n, r, depth+1);
//         swap(Arr[depth], Arr[i]);
//     }
// }

// // combi
// vector<int> Stack;
// void combi(int n, int r, int start){
//     if (Stack.size()==r){
//         for (int i=0; i<r; i++){
//             cout << Stack[i] << " ";
//         }
//         cout << "\n";
//         return;
//     }
//     for (int i=start; i<n; i++) {
//         Stack.push_back(Arr[i]);
//         combi(n, r, i+1);
//         Stack.pop_back();
//     }
// }

// int main() {
//     Arr = {1,2,3};
//     cout << "[permu]" << "\n";
//     permu(Arr.size(), 2, 0);
//     cout << "[combi]" << "\n";
//     combi(Arr.size(), 2, 0);
//     return 0;
// }

