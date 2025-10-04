#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    // ios::sync_with_stdio(false);  // C I/O와 동기화 끊기
    // cin.tie(nullptr);             // cin과 cout 묶음 풀기 (자동 flush 방지)
    
    ios::sync_with_stdio(false); // C I/O와 C++ I/O를 분리해서 더 빠르게
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    map<string, string> S2N;
    map<string, string> N2S;
    for (int i=1; i<=N; i++){
        string tmp;
        cin >> tmp;
        // Names.push_back({i, tmp});
        S2N[tmp]=to_string(i);
        N2S[to_string(i)]=tmp;
    }
    vector<string> Qs;
    for (int i=1; i<=M; i++) {
        string tmp;
        cin >> tmp;
        Qs.push_back(tmp);
    }
    for (auto q : Qs) {
        bool is_num = false;
        for (auto c : q) {
            if (c < 'A') is_num = true;
        }
        if (is_num) cout << N2S[q] << '\n';
        else cout << S2N[q] << '\n';
        // try {
        //     int tmp = stoi(q);
        //     cout << N2S[q] << endl;
        // } catch (const std::exception&) {  // 예외(문자 포함 등) 발생하면
        //     cout << S2N[q] << endl;
        // }
    }
    return 0;
}