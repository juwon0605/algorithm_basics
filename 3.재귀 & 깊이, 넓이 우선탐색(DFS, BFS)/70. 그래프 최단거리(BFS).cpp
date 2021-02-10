//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
70. 그래프 최단거리(BFS)
다음 그래프에서 1번 정점에서 각 정점으로 가는 최소 이동 간선수를 출력하세요.
1 2 5
3 4 6
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
1번 정점에서 각 정점으로 가는 최소 간선수를 2번 정점부터 차례대로 출력하세요.
*/
void BFS(int v);
vector<int> list[21];
queue<int> Q;
int flag[21];
int res[21];
int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, v1, v2;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> v1 >> v2;
		list[v1].push_back(v2);
	}
	flag[1] = 1;
	BFS(1);
	for (int i = 2; i <= n; i++) {
		cout << i << " : " << res[i] << endl;
	}
	return 0;
}
void BFS(int v) {
	Q.push(v);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < list[cur].size(); i++) {
			if (flag[list[cur][i]] == 0) {
				Q.push(list[cur][i]);
				flag[list[cur][i]] = 1;
				res[list[cur][i]] = res[cur] + 1;
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
int ch[30], dis[30];
int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, a, b, x, i;
	vector<int> map[30];
	queue<int> Q;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}
	Q.push(1);
	ch[1]=1;
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=0; i<map[x].size(); i++){
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q.push(map[x][i]);
				dis[map[x][i]]=dis[x]+1;
			}
		}
	}
	for(i=2; i<=n; i++){
		printf("%d : %d\n", i, dis[i]);
	}
	return 0;
}
*/

/*
모범 답안 반영 전
void BFS(int v);
vector<int> list[21];
queue<int> Q;
int flag[21];
int res[21];
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, v1, v2;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> v1 >> v2;
		list[v1].push_back(v2);
	}
	BFS(1);
	for (int i = 2; i <= n; i++) {
		cout << i << " : " << res[i] << endl;
	}
	return 0;
}
void BFS(int v) {
	Q.push(v);
	int cnt = 1;
	queue<int> temp;
	while (!Q.empty()) {
		bool isPush = false;
		int cur = Q.front();
		for (int i = 0; i < list[cur].size(); i++) {
			if (flag[list[cur][i]] == 0) {
				isPush = true;
				Q.push(list[cur][i]);
				temp.push(list[cur][i]);
				flag[list[cur][i]] = 1;
			}
		}
		if (isPush) {
			while (!temp.empty()) {
				res[temp.front()] = cnt;
				temp.pop();
			}
			cnt++;
		}
		Q.pop();
	}
}
*/