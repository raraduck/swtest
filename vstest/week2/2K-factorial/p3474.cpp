#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int cnt2=0;
        int cnt5=0;
        for (int i=2; i<=N; i*=2){
            cnt2 += N/i;
        }
        for (int i=5; i<=N; i*=5){
            cnt5 += N/i;
        }
        cout << min(cnt2, cnt5) << "\n";
    }
    return 0;
}