#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;
// https://www.acmicpc.net/problem/1620
int main()
{
    int N; // 포켓몬 개수   1~100,000
    int M; // 문제의 수     1~100,000
    // vector<> Pname; // 포켓몬 이름; 2~20;
    map <string, string> S2I;
    map <string, string> I2S;
    vector<string> Q;

    cin >> N >> M;
    string tmp;
    for (int i=1; i<=N; i++){
        string num = to_string(i);
        cin >> tmp;
        S2I[tmp] = num;
        I2S[num] = tmp;
    }
    for (int i=1; i<=M; i++){
        cin >> tmp;
        Q.push_back(tmp);
    }
    cout << '\n';
    for (auto q : Q){
        if(atoi(q.c_str())) {
            cout << I2S[q] << ' ';
        } else {
            cout << S2I[q] << ' ';
        }
    }
    cout << '\n';
    system("pause");  // "아무 키나 누르세요..." 출력됨
    return 0;
}