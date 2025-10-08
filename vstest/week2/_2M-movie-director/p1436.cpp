#include <iostream>
#include <string>

using namespace std;
int N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int cnt=0;
    int i=666;
    while(true) {
        if (to_string(i).find("666") != string::npos) {
            cnt++;
            // cout << cnt << ":" << i << "\n";
        }
        if (cnt == N) {
            cout << i;
            break;
        }
        i++;
    }
    return 0;
}