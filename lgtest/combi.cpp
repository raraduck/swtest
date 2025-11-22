#include <iostream>
#include <vector>
using namespace std;

vector<int> Arr = {1, 2, 3};
vector<int> result;

void dfs(int n, int r, int start) {
    if (result.size() == r) {
        for (int x : result) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < n; i++) {
        result.push_back(Arr[i]);
        dfs(n, r, i + 1);
        result.pop_back();
    }
}

int main() {
    dfs(3, 2, 0);   // n=3, r=2
    return 0;
}
