#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B, C;
    cin >> A >> B >> C;
    for (int i = 0; i < B; i++) {
        A *= A;
        A %= C;
    }
    cout << A << '\n';
    return 0;
}