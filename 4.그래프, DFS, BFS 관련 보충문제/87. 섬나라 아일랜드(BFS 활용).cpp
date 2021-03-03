/*
87. 섬나라 아일랜드(BFS 활용)
섬나라 아일랜드의 지도가 격자판의 정보로 주어집니다. 각 섬은 1로 표시되어 상하좌우와 대
각선으로 연결되어 있으며, 0은 바다입니다. 섬나라 아일랜드에 몇 개의 섬이 있는지 구하는
프로그램을 작성하세요.
1 1 0 0 0 1 0
0 1 1 0 1 1 0
0 1 0 0 0 0 0
0 0 0 1 0 1 1
1 1 0 1 1 0 0
1 0 0 0 1 0 0
1 0 1 0 1 0 0
만약 위와 같다면
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=20)이 주어집니다.
두 번째 줄부터 격자판 정보가 주어진다.
▣ 출력설명
첫 번째 줄에 섬의 개수를 출력한다.
▣ 입력예제 1
7
1 1 0 0 0 1 0
0 1 1 0 1 1 0
0 1 0 0 0 0 0
0 0 0 1 0 1 1
1 1 0 1 1 0 0
1 0 0 0 1 0 0
1 0 1 0 1 0 0
▣ 출력예제 1
5
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
using namespace std;

void BFS(int, int);
int map[22][22], flag[22][22];
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1 && flag[i][j] == 0) {
				BFS(i, j);
			}
		}
	}
	cout << cnt;
	return 0;
}
void BFS(int a, int b) {
	flag[a][b] = 1;
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();
		int i = now.first, j = now.second;
		for (int k = 0; k < 8; k++) {
			if (map[i + dy[k]][j + dx[k]] == 1 && flag[i + dy[k]][j + dx[k]] == 0) {
				flag[i + dy[k]][j + dx[k]] = 1;
				Q.push(make_pair(i + dy[k], j + dx[k]));
			}
		}
	}
	cnt++;
}

/*
모범 답안
#include<stdio.h>
#include<queue>
using namespace std;
int n, map[30][30], cnt=0;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
struct Loc{
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
queue<Loc> Q;
int main() {
	//freopen("input.txt", "rt", stdin);
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) scanf("%d", &map[i][j]);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(map[i][j] == 1) {
				Q.push(Loc(i, j));
				map[i][j] = 0;
				while(!Q.empty()) {
					Loc tmp = Q.front();
					Q.pop();
					for(int i = 0; i < 8; i++) {
						int xx=tmp.x+dx[i];
						int yy=tmp.y+dy[i];
						if(map[xx][yy] == 1) {
							Q.push(Loc(xx, yy));
							map[xx][yy]= 0;
						}
					}
				}
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
*/