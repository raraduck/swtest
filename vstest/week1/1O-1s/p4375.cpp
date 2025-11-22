#include <iostream>

using namespace std;
#define DEBUG 1

vector<int> N={3, 7, 9901};
int main() {
    int n;
    int tmp;
    int i=0;
    while (true) {
        if (DEBUG){
            n = N[i];
        } else {
            cin >> n;
        }
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
        i++;
    }
    return 0;
}
