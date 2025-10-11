// 반례 검색: https://testcase.ac/problems/1068 
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 1
#define RELEASE 0

using namespace std;

void print(vector<int>& arr) {
    cout << ">>>>\n";
    for (auto el:arr){
        cout << el << " ";
    }
    cout << "\n<<<<\n";
}

void display(vector<vector<int>>& arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << "(";
        for (auto n:arr[i]) {
            cout << n << " ";
        }
        cout << ") \n";
    }
}

int N, M;
int leaf_counter=0;
vector<int> Parents;
vector<vector<int>> Nodes;
vector<int> updated_Parents;
vector<int> Leafs;

void dfs_count_leaf(int nid, vector<vector<int>>& nodes) {
    // if (nid == M) {
    //     return;
    // }
    if (nodes[nid].size() == 0 ){
        leaf_counter += 1;
        Leafs.push_back(nid);
        return;
    } else {
        for (int i=0; i<nodes[nid].size(); i++) {
            if (nodes[nid][i] == M) {
                if (nodes[nid].size()==1) leaf_counter+=1;
            } else{
                dfs_count_leaf(nodes[nid][i], nodes);
            }
        }
    }
}

int main(){
    if (RELEASE) ios::sync_with_stdio(false);
    if (RELEASE) cin.tie(NULL);

    cin >> N;
    Parents = vector<int>(N);
    for (int i=0; i<N; i++) cin >> Parents[i];
    cin >> M;
    Nodes = vector<vector<int>>(N);
    int root;
    for (int i=0; i<N; i++){
        if (Parents[i] == -1) {
            root=i;
            continue;
        } else {
            int p = Parents[i];
            Nodes[p].push_back(i);
        }
    }

    dfs_count_leaf(root, Nodes);
    if (M == root) {
        cout << 0;
        return 0;
    } else {
        if (leaf_counter == 0) cout << 1 << "\n";
        else cout << leaf_counter << "\n";
        return 0;
        // cout << leaf_counter << "\n";
        // return;
    }
    // // for (auto n:Leafs) cout << n << "\n";
    // if (M==0) {
    //     cout << 0 << "\n";
    //     return 0;
    // } else {
    //     if (leaf_counter == 0) cout << 1 << "\n";
    //     else cout << leaf_counter << "\n";
    //     return 0;
    // }

    return 0;
}