//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
79. 원더랜드(Prim MST 알고리즘 : priority_queue 활용)
원더랜드에 문제가 생겼다. 원더랜드의 각 도로를 유지보수하는 재정이 바닥난 것이다.
원더랜드는 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록 도로를 선택하고 나머지
도로는 폐쇄하려고 한다. 어떤 도로는 도로를 유지보수하면 재정에 도움이 되는 도로도 존재
한다. 재정에 도움이 되는 도로는 비용을 음수로 표현했다.
아래의 그림은 그 한 예를 설명하는 그림이다.


위의 지도는 각 도시가 1부터 9로 표현되었고, 지도의 오른쪽은 최소비용 196으로 모든 도시
를 연결하는 방법을 찾아낸 것이다.
▣ 입력설명
첫째 줄에 도시의 개수 V(1≤V≤100)와 도로의 개수 E(1≤E≤1,000)가 주어진다. 다음 E개의
줄에는 각 도로에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 도시와 B번
도시가 유지비용이 C인 도로로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이
1,000,000을 넘지 않는다.
▣ 출력설명
모든 도시를 연결하면서 드는 최소비용을 출려한다.
*/
struct Edge
{
	int v1;
	int v2;
	int cost;
	Edge() : v1(0), v2(0), cost(0) {
	}
	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		cost = c;
	}
	bool operator<(const Edge &b) const {
		return cost > b.cost;
	}
};
vector<pair<int, int>> list[101];
int flag[101];
int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int v, e, a, b, c, res = 0, cnt = 1;
	priority_queue<Edge> pQ;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		list[a].push_back(make_pair(b, c));
		list[b].push_back(make_pair(a, c));
	}
	flag[1] = 1;
	for (int i = 0; i < list[1].size(); i++) {
		pQ.push(Edge(1, list[1][i].first, list[1][i].second));
	}
	while (!pQ.empty() && cnt <= v) {
		Edge e = pQ.top();
		pQ.pop();
		if (flag[e.v2] == 0) {
			flag[e.v2] = 1;
			res += e.cost;
			cnt++;
			for (int j = 0; j < list[e.v2].size(); j++) {
				pQ.push(Edge(e.v2, list[e.v2][j].first, list[e.v2][j].second));
			}
		}
	}
	cout << res;
	return 0;
}

/*
모범 답안
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int ch[30];
struct Edge{
	int e;
	int val;
	Edge(int a, int b){
		e=a;
		val=b;
	}
	bool operator<(const Edge &b)const{
		return val>b.val;
	}
};
int main(){
	freopen("input.txt", "rt", stdin);
	priority_queue<Edge> Q;
	vector<pair<int, int> > map[30];
	int i, n, m, a, b, c, res=0;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	Q.push(Edge(1, 0));
	while(!Q.empty()){
		Edge tmp=Q.top();
		Q.pop();
		int v=tmp.e;
		int cost=tmp.val;
		if(ch[v]==0){
			res+=cost;
			ch[v]=1;
			for(i=0; i<map[v].size(); i++){
				if(ch[map[v][i].first]==0){
					Q.push(Edge(map[v][i].first, map[v][i].second));
				}
			}
		}

	}
	printf("%d\n", res);
	return 0;
}
*/