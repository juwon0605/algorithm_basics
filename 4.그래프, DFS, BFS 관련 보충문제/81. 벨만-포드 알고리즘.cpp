/*
81. 벨만-포드 알고리즘
N개의 도시가 주어지고, 각 도시들을 연결하는 도로와 해당 도로를 통행하는 비용이 주어질
때 한 도시에서 다른 도시로 이동하는데 쓰이는 비용의 최소값을 구하는 프로그램을 작성하세
요.


▣ 입력설명
첫 번째 줄에는 도시의 수N(N<=100)과 도로수 M(M<=200)가 주어지고, M줄에 걸쳐 도로정보
와 비용이 주어진다. 만약 1번 도시와 2번도시가 연결되고 그 비용이 13이면 “1 2 13”으로
주어진다. 그 다음 마지막 줄에 출발도시와 도착도시가 주어진다.
▣ 출력설명
출발도시에서 도착도시까지 가는데 걸리는 최소비용을 출력한다. 음의 사이클이 존재할 경우
-1를 출력한다.
▣ 입력예제 1
5 7
1 2 5
1 3 4
2 3 -3
2 5 13
3 4 5
4 2 3
4 5 7
1 5
▣ 출력예제 1
14
*/

//#define _CRT_SECURE_NO_WARNINGS
#define INF 2147000000

#include<iostream>
#include<vector>
using namespace std;

struct Edge {
	int v1;
	int v2;
	int cost;
	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		cost = c;
	}
};
void BellmanFord(int);
int dist[101];
vector<Edge> edgeV;
bool cycle = false;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int m, a, b, c, start = 1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edgeV.push_back(Edge(a, b, c));
	}
	fill(dist, dist + 101, INF);
	BellmanFord(start);
	cout << (cycle == false ? dist[n] : -1);
	return 0;
}
void BellmanFord(int start) {
	dist[start] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edgeV.size(); j++) {
			int v1 = edgeV[j].v1;
			int v2 = edgeV[j].v2;
			int cost = edgeV[j].cost;
			if (dist[v1] != INF && dist[v1] + cost < dist[v2]) {
				dist[v2] = dist[v1] + cost;
			}
		}
	}
	for (int j = 0; j < edgeV.size(); j++) {
		int v1 = edgeV[j].v1;
		int v2 = edgeV[j].v2;
		int cost = edgeV[j].cost;
		if (dist[v1] != INF && dist[v1] + cost < dist[v2]) {
			cycle = true;
		}
	}
}
/*
모범 답안
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int dist[101];
struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
};
int main(){
	freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;
	int i, n, m, a, b, c, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}
	for(i=1; i<=n; i++){
		dist[i]=2147000000;
	}
	int s, e;
	scanf("%d %d", &s, &e);
	dist[s]=0;
	for(i=1; i<n; i++){
		for(j=0; j<Ed.size(); j++){
			int s=Ed[j].s;
			int e=Ed[j].e;
			int w=Ed[j].val;
			if(dist[s]!=2147000000 && dist[s]+w<dist[e]){
				dist[e]=dist[s]+w;
			}
		}
	}
	for(j=0; j<Ed.size(); j++){
		int u=Ed[j].s;
		int v=Ed[j].e;
		int w=Ed[j].val;
		if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
			printf("-1\n");
			exit(0);
		}
	}
	printf("%d\n", dist[e]);
	return 0;
}
*/