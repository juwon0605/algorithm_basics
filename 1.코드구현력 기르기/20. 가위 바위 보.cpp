//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
20. 가위 바위 보
A, B 두 사람이 가위바위보 게임을 합니다. 총 N번의 게임을 하여 A가 이기면 A를 출력하고,
B가 이기면 B를 출력합니다. 비길 경우에는 D를 출력합니다.
가위, 바위, 보의 정보는 1:가위, 2:바위, 3:보로 정하겠습니다.
예를 들어 N=5이면
회수 1 2 3 4 5
A의 정보 2 3 3 1 3
B의 정보 1 1 2 2 3
승자 A B A B D
두 사람의 각 회의 가위, 바위, 보 정보가 주어지면 각 회를 누가 이겼는지 출력하는 프로그램
을 작성하세요.
▣ 입력설명
첫 번째 줄에 게임 횟수인 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에는 A가 낸 가위, 바위, 보 정보가 N개 주어집니다.
세 번째 줄에는 B가 낸 가위, 바위, 보 정보가 N개 주어집니다.
▣ 출력설명
각 줄에 각 회의 승자를 출력합니다. 비겼을 경우는 D를 출력합니다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	int a[100];
	int b[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) cout << "D" << endl;
		else if ((a[i] == 1) && (b[i] == 2)) cout << "B" << endl;
		else if ((a[i] == 2) && (b[i] == 3)) cout << "B" << endl;
		else if ((a[i] == 3) && (b[i] == 1)) cout << "B" << endl;
		else cout << "A" << endl;
	}
	return 0;
}
/*
모범 답안
#include<stdio.h>
int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int a[101], b[101], i, j, n, A=0, B=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(i=1; i<=n; i++){
		scanf("%d", &b[i]);
	}
	for(i=1; i<=n; i++){
		if(a[i]==b[i]) printf("D\n");
		else if(a[i]==1 && b[i]==3) printf("A\n");
		else if(a[i]==2 && b[i]==1) printf("A\n");
		else if(a[i]==3 && b[i]==2) printf("A\n");
		else printf("B\n");
	}
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	int a[100];
	int b[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) cout << "D" << endl;
		else if (a[i] == 1) {
			if (b[i] == 2) cout << "B" << endl;
			else cout << "A" << endl;
		}
		else if (a[i] == 2) {
			if (b[i] == 3) cout << "B" << endl;
			else cout << "A" << endl;
		}
		else if (a[i] == 3) {
			if (b[i] == 1) cout << "B" << endl;
			else cout << "A" << endl;
		}
	}
	return 0;
}
*/
