#define _CRT_SECURE_NO_WARNINGS
#define INF 1e9

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
80. 다익스트라 알고리즘
아래의 가중치 방향그래프에서 1번 정점에서 모든 정점으로의 최소 거리비용을 출력하는 프로
그램을 작성하세요. (경로가 없으면 Impossible를 출력한다)


▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보와 거리비용이 주어진다.
▣ 출력설명
1번 정점에서 각 정점으로 가는 최소 비용을 2번 정점부터 차례대로 출력하세요.
*/
struct Edge {
	int v2;
	int cost;
	Edge(int a, int b) {
		v2 = a;
		cost = b;
	}
	bool operator<(const Edge &b) const {
		return cost > b.cost;
	}
};
void Dijkstra(int);
vector<Edge> graph[21];
int d[21];
int main() {
	ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m, a, b, c, start = 1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(Edge(b, c));
	}
	fill(d, d + 21, INF);
	Dijkstra(start);
	for (int i = 2; i <= n; i++) {
		cout << i << " : ";
		if (d[i] != INF) cout << d[i] << endl;
		else cout << "impossible" << endl;
	}
	return 0;
}
void Dijkstra(int start) {
	priority_queue<Edge> pQ;
	pQ.push(Edge(start, 0));
	d[start] = 0;
	while (!pQ.empty()) {
		int cur = pQ.top().v2;
		int auccum = pQ.top().cost;
		pQ.pop();
		if (d[cur] < auccum) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = auccum + graph[cur][i].cost;
			if (next < d[graph[cur][i].v2]) {
				d[graph[cur][i].v2] = next;
				pQ.push(Edge(graph[cur][i].v2, next));
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
int ch[30], dist[30];
vector<pair<int, int> > map[30];
int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, i, j, a, b, c, min;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
	}
	for(i=0; i<=n; i++) dist[i]=2147000000;
	dist[1]=0;
	for(i=1; i<=n; i++){
		min=0;
		for(j=1; j<=n; j++){
			if(ch[j]==0 && dist[j]<dist[min])
				min=j;
		}
		ch[min]=1;
		for(j=0; j<map[min].size(); j++){
			int v=map[min][j].x;
			int cost=map[min][j].y;
			if(dist[v]>dist[min]+cost){
				dist[v]=dist[min]+cost;
			}
		}
	}
	for(i=2; i<=n; i++){
		if(dist[i]!=2147000000) printf("%d : %d\n", i, dist[i]);
		else printf("%d : impossible\n", i);
	}
	return 0;
}
*/