#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int rem = 0;
        int k = 0;
        while (true) {
            k += 1;
            rem = (rem * 10 + 1);
            rem %= n;
            if (rem == 0) {
                cout << k << endl;
                break;
            }
        }
    }
    return 0;
}
