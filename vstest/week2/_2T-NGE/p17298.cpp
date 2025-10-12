#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1
#define RELEASE 0

int N;
int main() {
    if (RELEASE) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    cin >> N;
    vector<int> ORIG(N);
    vector<int> NEG(N, -1);
    for (int i=0; i<N; i++) cin >> ORIG[i];
    vector<int> STACK;
    for (int i=0; i<N; i++) {
        int orig = ORIG[i];
        while(STACK.size() && ORIG[STACK.back()] < ORIG[i]) {
            int idx = STACK.back();
            NEG[idx] = ORIG[i];
            STACK.pop_back();
        }
        STACK.push_back(i);
    }

    for (auto el:NEG) cout << el << " ";

    return 0;
}