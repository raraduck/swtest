#include <iostream>
#include <algorithm>
#include <iomanip> // setw 포함

using namespace std;

namespace P2559 {
#define DEBUG 0
	int main() {
		//int N = 10; //N은 온도를 측정한 전체 날짜의 수이다. N은 2 이상 100,000 이하
		//int K = 2; //K는 합을 구하기 위한 연속적인 날짜의 수이다. K는 1과 N 사이의 정수
		////둘째 줄에는 매일 측정한 온도를 나타내는 N개의 정수
		// 이 수들은 모두 -100 이상 100 이하
		//int T[] = { 3, -2, -4, -9, 0, 3, 7, 13, 8, -3 }; 
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
}