/*
88. 미로의 최단거리 통로(BFS 활용)
7*7 격자판 미로를 탈출하는 최단경로의 경로수를 출력하는 프로그램을 작성하세요. 경로수는
출발점에서 도착점까지 가는데 이동한 횟수를 의미한다. 출발점은 격자의 (1, 1) 좌표이고, 탈
출 도착점은 (7, 7)좌표이다. 격자판의 1은 벽이고, 0은 도로이다.
격자판의 움직임은 상하좌우로만 움직인다. 미로가 다음과 같다면
출발 0 0 0 0 0 0
0 1 1 1 1 1 0
0 0 0 1 0 0 0
1 1 0 1 0 1 1
1 1 0 1 0 0 0
1 0 0 0 1 0 0
1 0 1 0 0 0 도착
위와 같은 경로가 최단 경로이며 경로수는 12이다.
▣ 입력설명
첫 번째 줄부터 7*7 격자의 정보가 주어집니다.
▣ 출력설명
첫 번째 줄에 최단으로 움직인 칸의 수를 출력한다. 도착할 수 없으면 -1를 출력한다.
▣ 입력예제 1
0 0 0 0 0 0 0
0 1 1 1 1 1 0
0 0 0 1 0 0 0
1 1 0 1 0 1 1
1 1 0 1 0 0 0
1 0 0 0 1 0 0
1 0 1 0 0 0 0
▣ 출력예제 1
12
*/

//#define _CRT_SECURE_NO_WARNINGS
#define n 7

#include<iostream>
#include<queue>
using namespace std;

void BFS(int, int);
int map[n + 2][n + 2], flag[n + 2][n + 2], cnt[n + 2][n + 2];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	for (int i = 0; i <= n + 1; i++) {
		map[i][0] = 1;
		map[i][n+1] = 1;
		map[0][i] = 1;
		map[n + 1][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	flag[1][1] = 1;
	BFS(1, 1);
	cout << (cnt[n][n] != 0 ? cnt[n][n] : -1);
	return 0;
}

void BFS(int a, int b) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		int i = now.first, j = now.second;
		for (int k = 0; k < 4; k++) {
			int ii = i + dy[k], jj = j + dx[k];
			if (map[ii][jj] == 0 && flag[ii][jj] == 0) {
				flag[ii][jj] = 1;
				Q.push(make_pair(ii, jj));
				cnt[ii][jj] = cnt[i][j] + 1;
			}
		}
	}
}

/*
모범 답안
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	vector<vector<int> > board(7, vector<int>(7, 0));
	vector<vector<int> > dis(7, vector<int>(7, 0));
	queue<pair<int, int> > Q;
	for(int i=0; i<7; i++) {
		for(int j=0; j<7; j++) {
			cin>>board[i][j];
		}
	}
	Q.push(make_pair(0, 0));
	board[0][0]=1;
	while(!Q.empty()) {
		pair<int, int> tmp = Q.front();
		Q.pop();
		for(int i=0; i<4; i++) {
			int x=tmp.x+dx[i];
			int y=tmp.y+dy[i];
			if(x>=0 && x<7 && y>=0 && y<7 && board[x][y]==0) {
				Q.push(make_pair(x, y));
				board[x][y]=1;
				dis[x][y] = dis[tmp.x][tmp.y] + 1;
			}
		}
	}
	if(dis[6][6]==0) cout<<"-1";
	else cout<<dis[6][6];
	return 0;
}
*/