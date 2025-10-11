#include<bits/stdc++.h>
using namespace std;
int n, a[50], cut, ret;

void go(int cut){
	a[cut] = -2;
	for(int i = 0 ; i < n; i++){
		if(a[i] == cut) {
			go(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0 ; i < n; i++){
		cin >> a[i];
	}
	cin >> cut;
	go(cut);
	
//	for(int i = 0 ; i < n; i++){
//		cout << a[i] << " ";
//	}	
//	cout << '\n';

	// 리프노드 카운트만 하면됨.
	for(int i = 0 ; i < n; i++){
		int flag = 0;
		if(a[i] == -2) continue;
		for(int j = 0; j < n; j++){
			if(a[j] == i) flag++;
		}
		if(flag == 0) ret++;   
	}	 
	cout << ret << '\n';
}