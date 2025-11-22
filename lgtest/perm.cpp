#include <iostream>
#include <vector>

using namespace std;

vector<int> Arr = {1,2,3};

void dfs(int n, int r, int depth) {
    if (depth == r) {
        for (int i=0; i<r; i++){
            cout << Arr[i] << " ";
        }
        cout << "\n";
    }
    for (int i=depth; i<n; i++){
        swap(Arr[depth], Arr[i]);
        dfs(n, r, depth+1);
        swap(Arr[depth], Arr[i]);
    }
}

int main() {

    dfs(3, 3, 0);
    return 0;
}