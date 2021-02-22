#include<iostream>
using namespace std;

/*
83. 복면산 SEND+MORE=MONEY (MS인터뷰)
SEND+MORE=MONEY 라는 유명한 복면산이 있습니다. 이 복면산을 구하는 프로그램을 작성
하세요.
출력형태
 9 5 6 7
+ 1 0 8 5
---------
1 0 6 5 2
*/
void DFS(int);
int SEND();
int MORE();
int MONEY();
int arr[8], flag[10];
int main() {
	ios::sync_with_stdio(false);
	DFS(0);
	return 0;
}
int SEND() {
	return (arr[6] * 1000) + (arr[1] * 100) + (arr[3] * 10) + (arr[0]);
}
int MORE() {
	return (arr[2] * 1000) + (arr[4] * 100) + (arr[5] * 10) + (arr[1]);
}
int MONEY() {
	return (arr[2] * 10000) + (arr[4] * 1000) + (arr[3] * 100) + (arr[1] * 10) + (arr[7]);
}
void DFS(int L) {
	if (L == 8) {
		if (SEND() + MORE() == MONEY()) {
			if (arr[2] == 0 || arr[6] == 0) return;
			cout << " " << arr[6] << " " << arr[1] << " " << arr[3] << " " << arr[0] << endl;
			cout << "+" << arr[2] << " " << arr[4] << " " << arr[5] << " " << arr[1] << endl;
			cout << "---------" << endl;
			cout << arr[2] << " " << arr[4] << " " << arr[3] << " " << arr[1] << " " << arr[7] << endl;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (flag[i] == 0) {
				flag[i] = 1;
				arr[L] = i;
				DFS(L + 1);
				flag[i] = 0;
			}
		}
	}
}

/*
모범 답안
#include<stdio.h>
using namespace std;
int a[10], ch[10];
int send() {
	return a[6]*1000+a[1]*100+a[3]*10+a[0];
}
int more() {
	return a[2]*1000+a[4]*100+a[5]*10+a[1];
}
int money() {
	return a[2]*10000+a[4]*1000+a[3]*100+a[1]*10+a[7];
}
void P(int L) {
	if(L==8) {
		if(send()+more()==money()){
			if(a[2] == 0 || a[6] == 0) return;
			printf("  %d %d %d %d\n", a[6], a[1], a[3], a[0]);
			printf("+ %d %d %d %d\n", a[2], a[4], a[5], a[1]);
			printf("---------\n");
			printf("%d %d %d %d %d\n", a[2], a[4], a[3], a[1], a[7]);
		}
	}
	else {
		for(int i=0; i<10; i++) {
			if(ch[i]==0) {
				a[L]=i;
				ch[i]=1;
				P(L+1);
				ch[i]=0;
			}
		}
	}
}
int main() {
	P(0);
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	string change = "OMY--ENDRS";
	string str;
	getline(cin, str);
	cout << "  ";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			cout << "\n+ ";
		}
		else if (str[i] == '=') {
			cout << "\n---------\n";
		}
		else {
			for (int j = 0; j < change.size(); j++) {
				if (str[i] == change[j]) cout << j << " ";
			}
		}
	}
	return 0;
}
*/