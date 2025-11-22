#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
#define DEBUG 1
typedef long long ll;
// 25/11/22 7시30분 시작
// 25/11/22 8시43분 종료 (1시간13분 소요)
int main() {
    if (!DEBUG) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }

    ll N;// 직원수 N명 (1~100,000)
    ll T;// 산책시간 T분 (1~1,000,000,000)
    vector<ll> P;// 출발위치 [P1, P2, ..., Pn] (1~1,000,000,000)
    vector<ll> S;// 산책속도 [S1, S2, ..., Sn] (~1,000,000,000)

    if (DEBUG) {
        // Case1
        // N=4, T=10;
        // P={0, 2, 4, 6};
        // S={4, 3, 2, 1};
        // 답: ST = [16, 16, 16, 16]

        // Case2
        // N=5, T=100;
        // P = {0, 10, 20, 30, 40};
        // S = {1, 1, 1, 1, 1};
        // 답: ST = [100, 110, 120, 130, 140]

        // Case3
        // N=5, T=10;
        // P = {0, 5, 10, 15, 20};
        // S = {10, 9, 8, 7, 6};
        // 답: ST = [80, 80, 80, 80, 80]

        // Case4
        // N=6, T=5;
        // P = {0, 2, 4, 10, 20, 30};
        // S = {10, 9, 8, 1, 2, 1};
        // 답: ST = [15, 15, 15, 15, 30, 35]

        N=6, T=10;
        P = {0, 1, 2, 3, 100, 200};
        S = {20, 10, 5, 3, 1, 1};
        // ST = [33, 33, 33, 33, 110, 210]

        // N=7, T=10;
        // P = {0, 5, 10, 15, 20, 25, 30};
        // S = {10, 1, 10, 1, 10, 1, 10};
        // ST = [15, 15, 25, 25, 35, 35, 130];

    } else {
        cin >> N >> T;
        vector<pair<ll, ll>> people(N); 
        // pair: (x, v)
        for (int i = 0; i < N; i++) {
            cin >> people[i].first >> people[i].second;
        }
        // 1. 위치 기준으로 뒤에서 앞으로 볼 것이므로, 위치 오름차순 정렬
        sort(people.begin(), people.end()); // x 기준 오름차순

        for (auto el : people){
            P.push_back(el.first);
            S.push_back(el.second);
        }
    }
    // T 시간 개별진행
    for (int i=0;i<N;i++){
        P[i] = P[i] + T * S[i];
    }
    if (DEBUG){
        for (auto el : P){
            cout << el << " ";
        }
        cout << "\n";
    }

    vector<ll> ST = P;
    deque<ll> iQue;
    for (ll i=(N-1); i>=0; i--) {
        while(iQue.size() && P[iQue.front()] > P[i]) {
            ll _i = iQue.back();
            ST[_i] = P[iQue.front()];
            iQue.pop_back();
        }
        iQue.push_back(i);
        if (i==0){
            while(iQue.size()){
                ll _i = iQue.back();
                ST[_i] = P[iQue.front()];
                iQue.pop_back();
            }
        }
    }
    if (DEBUG){
        for (auto el : ST){
            cout << el << " ";
        }
        cout << "\n";
    }
    ST.erase(unique(ST.begin(), ST.end()), ST.end());
    cout << ST.size();   

    return 0;
}