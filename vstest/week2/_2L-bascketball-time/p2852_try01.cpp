#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string tick="";
    string prev_tick="00:00";
    int en_record = 0;
    int team=0;
    int team1_c_score=0;
    int team2_c_score=0;
    int team1_p_score=0;
    int team2_p_score=0;
    int team1_time=0;
    int team2_time=0;
    int prev_toc=0;

    auto tick2sec = [](string tick, string prev) {
        string tick_min = tick.substr(0,2);
        string tick_sec = tick.substr(3,2);
        int tick_seconds = stoi(tick_min)*60 + stoi(tick_sec);
        string prev_min = prev.substr(0,2);
        string prev_sec = prev.substr(3,2);
        int prev_seconds = stoi(prev_min)*60 + stoi(prev_sec);
        int acc_seconds = tick_seconds - prev_seconds;
        // string tick_acc = to_string(acc_seconds/60) + ":" + to_string(acc_seconds%60);
        // cout << acc_seconds << ":" << tick_acc << "\n";
        return acc_seconds;
    };

    for (int i=0; i<=N; i++) {
        if (i<N) cin >> team >> tick;
        else {team=0; tick="48:00";}

        if (team==1) team1_c_score+=1;
        if (team==2) team2_c_score+=1;
        
        if (team1_p_score > team2_p_score) team1_time += tick2sec(tick, prev_tick);
        if (team1_p_score < team2_p_score) team2_time += tick2sec(tick, prev_tick);

        prev_tick = tick;
        team1_p_score = team1_c_score;
        team2_p_score = team2_c_score;
    }
    int team1_m = team1_time/60, team1_s = team1_time%60;
    string team1_min = (team1_m < 10) ? "0"+to_string(team1_time/60):to_string(team1_time/60);
    string team1_sec = (team1_s < 10) ? "0"+to_string(team1_time%60):to_string(team1_time%60);
    int team2_m = team2_time/60, team2_s = team2_time%60;
    string team2_min = (team2_m < 10) ? "0"+to_string(team2_time/60):to_string(team2_time/60);
    string team2_sec = (team2_s < 10) ? "0"+to_string(team2_time%60):to_string(team2_time%60);
    cout << team1_min+":"+team1_sec << "\n";
    cout << team2_min+":"+team2_sec << "\n";
    return 0;
}