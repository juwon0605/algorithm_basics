/*
12. 플로이드 워샬 알고리즘
N개의 도시가 주어지고, 각 도시들을 연결하는 도로와 해당 도로를 통행하는 비용이 주어질
때 모든 도시에서 모든 도시로 이동하는데 쓰이는 비용의 최소값을 구하는 프로그램을 작성하
세요.


▣ 입력설명
첫 번째 줄에는 도시의 수N(N<=100)과 도로수 M(M<=200)가 주어지고, M줄에 걸쳐 도로정보
와 비용(20 이하의 자연수)이 주어진다. 만약 1번 도시와 2번도시가 연결되고 그 비용이 13이
면 “1 2 13”으로 주어진다.
▣ 출력설명
모든 도시에서 모든 도시로 이동하는데 드는 최소 비용을 아래와 같이 출력한다.
자기자신으로 가는 비용은 0입니다. i번 정점에서 j번 정점으로 갈 수 없을 때는 비용을 “M"으
로 출력합니다.
▣ 입력예제 1
5 8
1 2 6
1 3 3
3 2 2
2 4 1
2 5 13
3 4 5
4 2 3
4 5 7
▣ 출력예제 1
0 5 3 6 13 //1번 정점에서 2번정점으로 5, 1에서 3번 정점으로 3, 1에서 4번 정점으로 6......
M 0 M 1 8 //2번 정점에서 1번 정점으로는 갈수 없으므로 “M", .......
M 2 0 3 10
M 3 M 0 7
M M M M 0
*/


//#define _CRT_SECURE_NO_WARNINGS
#define INF 4000

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	vector<vector<int>> dp(101, vector<int>(101, INF));
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dp[a][b] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] != INF) cout << dp[i][j] << " ";
			else cout << "M ";
		}
		cout << "\n";
	}
	return 0;
}

/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m, a, b, c;
	cin>>n>>m;
	vector<vector<int> > dis(n+1, vector<int>(n+1, 5000));
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int i=1; i<=m; i++){
		cin>>a>>b>>c;
		dis[a][b]=c;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dis[i][j]==5000){
				cout<<"M ";
			}
			else cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
*/

/*
모범 답안 반영 전
	다익스트라를 N번 사용해서 풀었음! (시간 복잡도는 동일)

//#define _CRT_SECURE_NO_WARNINGS
#define INF 30

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
vector<Edge> graph[201];
int d[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int n, m, a, b, c, start;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(Edge(b, c));
	}
	for (int i = 1; i <= n; i++) {
		fill(d, d + n + 1, INF);
		start = i;
		Dijkstra(start);
		for (int j = 1; j <= n; j++) {
			if (d[j] != INF) cout << d[j] << " ";
			else cout << "M" << " ";
		}
		cout << "\n";
	}
	return 0;
}
void Dijkstra(int start) {
	priority_queue<Edge> pQ;
	pQ.push(Edge(start, 0));
	d[start] = 0;
	while (!pQ.empty()) {
		int cur = pQ.top().v2;
		int accum = pQ.top().cost;
		pQ.pop();
		if (d[cur] < accum) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = accum + graph[cur][i].cost;
			if (next < d[graph[cur][i].v2]) {
				d[graph[cur][i].v2] = next;
				pQ.push(Edge(graph[cur][i].v2, next));
			}
		}
	}
}
*/