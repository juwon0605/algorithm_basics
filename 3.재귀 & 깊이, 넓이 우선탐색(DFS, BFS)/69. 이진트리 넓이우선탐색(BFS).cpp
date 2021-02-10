//#define _CRT_SECURE_NO_WARNINGS
#define n 6

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
69. 이진트리 넓이우선탐색(BFS)
아래 그림과 같은 이진트리를 넓이우선탐색해 보세요. 간선 정보 6개를 입력받아 처리해보세
요.
   1
  2 3
4 5 6 7
넓이 우선 탐색 : 1 2 3 4 5 6 7
*/
void BFS(int);
vector<vector<int>> list(n + 2);
int flag[n + 2];
int main() {
	//freopen("input.txt", "rt", stdin);
	int v1, v2;
	for (int i = 1; i <= n; i++) {
		cin >> v1 >> v2;
		list[v1].push_back(v2);
		list[v2].push_back(v1);
	}
	flag[1] = 1;
	BFS(1);
	return 0;
}
void BFS(int v) {
	queue<int> queqe;
	queqe.push(v);
	while (!queqe.empty()) {
		int cur = queqe.front();
		queqe.pop();
		cout << cur << " ";
		for (int i = 0; i < list[cur].size(); i++) {
			if (flag[cur] == 0) {
				queqe.push(list[cur][i]);
				flag[list[cur][i]] = 1;
			}
		}
	}
}

/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int Q[100], front=-1, back=-1, ch[10];
vector<int> map[10];
int main(){
	freopen("input.txt", "rt", stdin);
	int i, a, b, x;
	for(i=1; i<=6; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	Q[++back]=1;
	ch[1]=1;
	while(front<back){
		x=Q[++front];
		printf("%d ", x);
		for(i=0; i<map[x].size(); i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q[++back]=map[x][i];
			}
		}
	}
	return 0;
}
*/

/*
모범 답안 반영 전
void BFS(int);
vector<vector<int>> list(n + 2);
queue<int> queqe;

int main() {
	freopen("input.txt", "rt", stdin);
	int v1, v2;
	for (int i = 1; i <= n; i++) {
		cin >> v1 >> v2;
		list[v1].push_back(v2);
	}
	cout << 1 << " ";
	BFS(1);
	return 0;
}
void BFS(int v) {
	queqe.push(v);
	while (!queqe.empty()) {
		int cur = queqe.front();
		for (int i = 0; i < list[cur].size(); i++) {
			cout << list[cur][i] << " ";
			queqe.push(list[cur][i]);
		}
		queqe.pop();
	}
}
*/