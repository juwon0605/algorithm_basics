/*
90. 라이언 킹 심바(삼성 SW역량평가 기출 : BFS활용)
N×N 크기의 정글에 토끼 M마리와 어린 사자 심바가 있다. 정글은 1×1 크기의 격자로 이루
어져 있다. 각 격자칸에는 토끼 1한마리가 있거나 또는 없을 수 있다. 어린 사자 심바는 주어
진 정글에서 토끼를 잡아먹고 덩치를 키워 삼촌 스카에게 복수를 하러 갈 예정이다.
어린 사자 심바와 토끼는 모두 몸 크기를 가지고 있고, 이 크기는 자연수이다. 가장 처음에 어
린 사자 심바의 크기는 2이고, 심바는 1초에 인접한 상하좌우 격자칸으로 이동할 수 있다.
어린 사자 심바는 자신보다 크기가 큰 토끼가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지
나갈 수 있다. 심바는 자신보다 크기가 작은 토끼만 잡아먹을 수 있다. 크기가 같은 토끼는 먹
을 수는 없지만, 그 토끼가 있는 칸은 지날 수 있다.
어린 사자 심바가 토끼를 잡아먹기 위한 이동규칙은 다음과 같다.
1) 더 이상 먹을 수 있는 토끼가 정글에 없다면 이제 심바는 삼촌 스카에게 복수하러 갈 수
있다.
2) 먹을 수 있는 토끼가 딱 한마리라면, 그 토끼를 먹으러 간다.
3) 먹을 수 있는 토끼가 2마리 이상이면, 거리가 가장 가까운 토끼를 먹으러 간다.
 ① 거리는 심바가 있는 칸에서 먹으려고 하는 토끼가 있는 칸으로 이동할 때, 지나야하는 칸
 의 개수의 최소값이다.
 ② 가장 가까운 토끼가 많으면, 그 중 가장 위쪽에 있는 토끼, 그러한 토끼가 여러 마리라
 면, 가장 왼쪽에 있는 토끼를 잡아먹는다.
심바가 격자칸 하나를 이동하는데 1초 걸리고, 토끼를 먹는데 걸리는 시간은 없다고 가정한다.
심바가 해당 격자칸의 토끼를 먹으면, 그 칸은 빈 칸이 된다.
심바는 자신의 몸 크기와 같은 마리수 만큼 잡아먹으면 몸의 크기가 1증가한다.
만약 심바의 몸크기가 5라면 자신보다 작은 토끼 5마리를 잡아먹으면 심바의 몸 크기는 6으로
변한다.
정글의 상태가 주어졌을 때, 심바가 몇 초 동안 토끼를 잡아먹고 삼촌 스카에게 복수를 하러
갈 수 있는지 구하는 프로그램을 작성하시오.
▣ 입력설명
첫 번째 줄에 정글의 크기 N(2 ≤ N ≤ 25)이 주어진다.
둘 번째 줄부터 정글의 지도 정보가 주어진다.
0은 빈칸이고, 각 토끼의 크기(1, 2, 3, 4, 5, 6, 7)과 9는 심바를 뜻한다.
▣ 출력설명
첫 번째 줄에 심바가 토끼를 잡아먹고 삼촌 스카에게 복수를 하러갈 수 있는 시간을 출력한
다.
▣ 입력예제 1
3
0 1 3
1 9 1
0 1 1
▣ 출력예제 1
10
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
using namespace std;

struct Simba {
	int y = 0;
	int x = 0;
	int size = 2;
	int eatNum = 0;
	Simba(){}
	Simba(int a, int b) {
		y = a;
		x = b;
	}
};
struct Rabit {
	int y = 0;
	int x = 0;
	int dis = 0;
	Rabit() {}
	Rabit(int a, int b, int c) {
		y = a;
		x = b;
		dis = c;
	}
	bool operator<(const Rabit &b) const {
		if (dis != b.dis) return dis > b.dis;
		else {
			if (y != b.y) return y > b.y;
			else return x > b.x;
		}
	}
};
void BFS(int, int);
Simba simba;
Rabit target;
int map[27][27], dis[27][27];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int n, res = 0;
bool finish = false;
int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				simba.y = i;
				simba.x = j;
			}
		}
	}
	BFS(simba.y, simba.x);
	while(!finish) {
		map[simba.y][simba.x] = 0;
		simba.y = target.y;
		simba.x = target.x;
		map[simba.y][simba.x] = 9;
		dis[simba.y][simba.x] = 0;
		res += target.dis;
		simba.eatNum++;
		if (simba.size == simba.eatNum) {
			simba.size++;
			simba.eatNum = 0;
		}
		BFS(simba.y, simba.x);
	}
	cout << res;
	return 0;
}
void BFS(int a, int b) {
	int flag[27][27] = { 0 };
	flag[a][b] = 1;
	priority_queue<Rabit> rabit_pQ;
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		int i = now.first;
		int j = now.second;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k];
			int jj = j + dx[k];
			if (ii < 1 || ii > n || jj < 1 || jj > n) continue;
			if (map[ii][jj] <= simba.size && flag[ii][jj] == 0) {
				flag[ii][jj] = 1;
				Q.push(make_pair(ii, jj));
				dis[ii][jj] = dis[i][j] + 1;
				if (map[ii][jj] > 0 && map[ii][jj] < simba.size) {
					rabit_pQ.push(Rabit(ii, jj, dis[ii][jj]));
				}
			}
		}
	}
	if (rabit_pQ.empty()) finish = true;
	else target = rabit_pQ.top();
}
/*
모범 답안
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int map[21][21], ch[21][21];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
struct State{
	int x, y, dis;
	State(int a, int b, int c){
		x=a;
		y=b;
		dis=c;
	}
//	bool operator<(const State &bb)const{
//		if(dis==bb.dis){
//			if(x==bb.x) return y>bb.y;
//			else return x>bb.x;
//		}
//		else return dis>bb.dis;
//	}
	bool operator<(const State &b)const{
		if(dis!=b.dis) return dis>b.dis;
		if(x!=b.x) return x>b.x;
		else return y>b.y;
	}
};
struct Lion{
	int x, y, s, ate;
	void sizeUp(){
		ate=0;
		s++;
	}
};
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, res=0;
	priority_queue<State> Q;
	Lion simba;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]==9){
				simba.x=i;
				simba.y=j;
				map[i][j]=0;
			}
		}
	}
	Q.push(State(simba.x, simba.y, 0));
	simba.s=2;
	simba.ate=0;
	while(!Q.empty()){
		State tmp=Q.top();
		Q.pop();
		int x=tmp.x;
		int y=tmp.y;
		int z=tmp.dis;
		if(map[x][y]!=0 && map[x][y]<simba.s){
			simba.x=x;
			simba.y=y;
			simba.ate++;
			if(simba.ate>=simba.s) simba.sizeUp();
			map[x][y]=0;
			for(i=1; i<=n; i++){
				for(j=1; j<=n; j++){
					ch[i][j]=0;
				}
			}
			while(!Q.empty()) Q.pop();
			res=tmp.dis;
		}
		for(i=0; i<4; i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1 || xx>n || yy<1 || yy>n || map[xx][yy]>simba.s || ch[xx][yy]>0) continue;
			Q.push(State(xx, yy, z+1));
			ch[xx][yy]=1;
		}
	}
	printf("%d\n", res);
	return 0;
}
*/