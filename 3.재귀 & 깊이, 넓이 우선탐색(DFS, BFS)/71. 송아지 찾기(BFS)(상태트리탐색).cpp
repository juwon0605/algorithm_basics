//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
71. 송아지 찾기(BFS : 상태트리탐색)
현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다. 현수의 위치와 송아
지의 위치가 직선상의 좌표 점으로 주어지면 현수는 현재 위치에서 송아지의 위치까지 다음과
같은 방법으로 이동한다.
현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수
있다. 최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성
하세요.
▣ 입력설명
첫 번째 줄에 현수의 위치 S와 송아지의 위치 E가 주어진다. 직선의 좌표 점은 1부터 10,000
까지이다.
▣ 출력설명
점프의 최소횟수를 구한다.
*/
void BFS(int);
int flag[10001];
int cnt[10001];
int e;
int main() {
	//freopen("input.txt", "rt", stdin);	
	int s;
	cin >> s >> e;
	flag[s] = 1;
	BFS(s);
	cout << cnt[e];
	return 0;
}
void BFS(int v) {
	queue<int> Q;
	Q.push(v);
	int dx[3] = { -1, 1, 5 };
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if (cur <= 0 || cur > 10000) continue;
		if (cur == e) return;
		for (int i = 0; i < 3; i++) {
			if (flag[cur + dx[i]] == 0) {
				Q.push(cur + dx[i]);
				flag[cur + dx[i]] = 1;
				cnt[cur + dx[i]] = cnt[cur] + 1;
			}
		}
	}
}

/*
모범 답안
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int ch[10001], d[3]={1, -1, 5};
int main(){
	freopen("input.txt", "rt", stdin);
	int s, e, x, pos, i;
	queue<int> Q;
	scanf("%d %d", &s, &e);
	ch[s]=1;
	Q.push(s);
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=0; i<3; i++){
			pos=x+d[i];
			if(pos<=0 || pos>10000) continue;
			if(pos==e){
				printf("%d\n", ch[x]);
				exit(0);
			}
			if(ch[pos]==0){
				ch[pos]=ch[x]+1;
				Q.push(pos);
			}
		}
	}
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	int s, e, cnt=0;
	cin >> s >> e;
	while (s != e) {
		if (s + 5 < e) s += 5;
		else {
			if (s + 3 < e) s += 5;
			else if(s < e) s += 1;
			else s -= 1;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
*/