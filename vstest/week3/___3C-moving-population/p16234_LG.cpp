#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1
#define RELEASE 1

int main() {
    if (RELEASE) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int N, L, R;
    if (DEBUG) {
        N = 2, L = 20, R = 50;
    } else {
        cin >> N >> L >> R;
    }
    cout << N << ", " << L << ", " << R << "\n";
        

    return 0;
}