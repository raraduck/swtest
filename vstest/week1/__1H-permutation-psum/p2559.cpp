#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define DEBUG 0
int main() {
    int N, K, SUM=0;
    int M[100001];
    int PSUM[100001] = {0};
    cin >> N >> K;
    if (DEBUG) cout << N << " " << K << "\n";
    for (int i = 1; i <= N; i++ ) {
        cin >> M[i];
        SUM += M[i];
        PSUM[i] = SUM;
    }
    if (DEBUG) {
        cout << "A" << ": ";
        for (int i = 1; i <= N; i++) {
            cout << setw(3) << M[i] << ' ';
        }
        cout << "\n";
        cout << "P" << ": ";
        for (int i = 1; i <= N; i++) {
            cout << setw(3) << PSUM[i] << ' ';
        }
        cout << "\n";
        for (int k = 2; k <= K; k++) {
            cout << k << ": ";
            for (int i = 1; i <= N ; i++) {
                if (i < k) cout << setw(3) << 0 << ' ';
                else cout << setw(3) << PSUM[i] - PSUM[i - k] << ' ';
            }
            cout << "\n";
        }
        cout << "\n";
    }
    int MaxSUM = 0;
    for (int k = 2; k <= K; k++) {
        if (DEBUG) cout << k << ": ";
        for (int i = 1; i <= N; i++) {
            int TMP = 0;  
            if (i < k) TMP = 0;
            else TMP = PSUM[i] - PSUM[i - k];
            if (TMP > MaxSUM) MaxSUM = TMP;
            if (DEBUG) cout << setw(3) << MaxSUM << " ";
        }
        if (DEBUG) cout << "\n";
    }
    cout << MaxSUM;

    return 0;
}