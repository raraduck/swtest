#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;
string full_time="08:00";
int full_seconds=2880;
int stime_to_isec(string stime){
    string s_min = stime.substr(0,2);
    string s_sec = stime.substr(3,2);
    int i_min = stoi(s_min);
    int i_sec = stoi(s_sec);
    int i_seconds = i_min * 60 + i_sec;
    return i_seconds;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    map <string, pair<int, int>> board = {
        {"1", {0, 0}},
        {"2", {0, 0}}
    };
    int prev_tick = 0;
    for (int i=0; i<N; i++) {
        string team, stime;
        cin >> team >> stime;
        int tick = stime_to_isec(stime);
        int tok = (i == 0) ? 0:tick-prev_tick;
        if (board["1"].first > board["2"].first) {
            board["1"].second += tok;
        } else if (board["1"].first < board["2"].first) {
            board["2"].second += tok;
        }
        board[team].first += 1;
        prev_tick = tick;
    }

    int tok = full_seconds-prev_tick;
    if (board["1"].first > board["2"].first) {
        board["1"].second += tok;
    } else if (board["1"].first < board["2"].first) {
        board["2"].second += tok;
    }

    auto itos = [](int v){return (v < 10 ? "0" : "") + to_string(v);};

    int i_min1 = board["1"].second / 60;
    int i_sec1 = board["1"].second % 60;
    cout << itos(i_min1) << ":" << itos(i_sec1);
    cout << "\n";
    int i_min2 = board["2"].second / 60;
    int i_sec2 = board["2"].second % 60;
    cout << itos(i_min2) << ":" << itos(i_sec2);
    cout << "\n";

    return 0;
}
// 5
// 2 00:00
// 2 00:01
// 2 00:02
// 1 00:04
// 1 00:05