//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

/*
68. 최소비용(DFS : 가중치 방향그래프 인접리스트)
가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그
램을 작성하세요.
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
총 가지수를 출력한다.
*/
void DFS(int, int);
vector<pair<int, int>> list[21];
int flag[1025];
int n, min = 2147000000;
int main() {
	//freopen("input.txt", "rt", stdin);
	int m, v1, v2, e;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> v1 >> v2 >> e;
		list[v1].push_back(make_pair(v2, e));
	}
	flag[1] = 1;
	DFS(1, 0);
	cout << min;
	return 0;
}
void DFS(int v, int accum) {
	if (v == n) {
		if (min > accum) min = accum;
		return;
	}
	else {
		for (int i = 0; i < list[v].size(); i++) {
			if (flag[list[v][i].first] == 0) {
				flag[list[v][i].first] = 1;
				DFS(list[v][i].first, accum + list[v][i].second);
				flag[list[v][i].first] = 0;
			}
		}
	}
}
/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
int ch[30], cnt=0, n, cost=2147000000;
vector<pair<int, int> > map[30];
void DFS(int v, int sum){
	int i;
	if(v==n){
		if(sum<cost) cost=sum;
	}
	else{
		for(i=0; i<map[v].size(); i++){
			if(ch[map[v][i].x]==0){
				ch[map[v][i].x]=1;
				DFS(map[v][i].x, sum+map[v][i].y);
				ch[map[v][i].x]=0;
			}
		}
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int m, i, a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
	}
	ch[1]=1;
	DFS(1, 0);
	printf("%d\n", cost);
	return 0;
}
*/