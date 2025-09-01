#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    int T;
    cout << "테스트케이스: ";
    cin >> T;
    for (int i =1; i<=T; i++){
        cout << "테스트케이스 " << i << " ";
        cout << "\n";
        int N;
        string CN, CT;
        map<string, vector <string>> Data;
        cout << "의상 수: ";
        cin >> N;
        for (int j =1; j<=N; j++){
            cout << "<의상이름> <종류>: ";
            cin >> CN >> CT;
            if (Data[CT].size() == 0) Data[CT].push_back("");
            Data[CT].push_back(CN);
        }
        for (auto& d : Data){
            string key = d.first;
            vector <string> values = d.second;
            cout << "의상이름과 종류: " << d.first << " ";
            cout << "[ ";
            for (auto v: values){
                cout << v << " ";
            }
            cout << "]";
            cout << "\n";
        }
        int Answer = 1;
        for (auto& d : Data){
            Answer *= d.second.size();
        }
        cout << Answer -1;
        cout << "\n";
    }
    system("pause");  // "아무 키나 누르세요..." 출력됨
    return 0;
}