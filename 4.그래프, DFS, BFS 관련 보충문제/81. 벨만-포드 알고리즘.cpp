#define _CRT_SECURE_NO_WARNINGS
#define INF 2147000000

#include<iostream>
#include<vector>
using namespace std;

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
*/
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
vector<Edge> edge_vec;
bool cycle = false;
int n;
int main() {
	ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int m, a, b, c, start=1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge_vec.push_back(Edge(a, b, c));
	}
	fill(dist, dist + 101, INF);
	BellmanFord(start);
	cout << (cycle == false ? dist[n] : -1);
	return 0;
}
void BellmanFord(int start) {
	dist[start] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edge_vec.size(); j++) {
			int v1 = edge_vec[j].v1;
			int v2 = edge_vec[j].v2;
			int cost = edge_vec[j].cost;
			if (dist[v1] != INF && dist[v1] + cost < dist[v2]) {
				dist[v2] = dist[v1] + cost;
			}
		}
	}
	for (int j = 0; j < edge_vec.size(); j++) {
		int v1 = edge_vec[j].v1;
		int v2 = edge_vec[j].v2;
		int cost = edge_vec[j].cost;
		if (dist[v1] != INF && dist[v1] + cost < dist[v2]) {
			cycle = true;
		}
	}
}
/*
모범 답안

*/

/*
모범 답안 반영 전

*/