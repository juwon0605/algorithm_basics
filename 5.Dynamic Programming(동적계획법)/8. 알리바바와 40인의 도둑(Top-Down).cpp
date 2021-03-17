/*
8. 알리바바와 40인의 도둑(Top-Down)
알리바바는 40인의 도둑으로부터 금화를 훔쳐 도망치고 있습니다.
알리바바는 도망치는 길에 평소에 잘 가지 않던 계곡의 돌다리로 도망가고자 한다.
계곡의 돌다리는 N×N개의 돌들로 구성되어 있다. 각 돌다리들은 높이가 서로 다릅니다.
해당 돌다리를 건널때 돌의 높이 만큼 에너지가 소비됩니다. 이동은 최단거리 이동을 합니다.
즉 현재 지점에서 오른쪽 또는 아래쪽으로만 이동해야 합니다.
N*N의 계곡의 돌다리 격자정보가 주어지면 (1, 1)격자에서 (N, N)까지 가는데 드는 에너지의
최소량을 구하는 프로그램을 작성하세요.
만약 N=3이고, 계곡의 돌다리 격자 정보가 다음과 같다면
3 3 5
2 3 4
6 5 2
(1, 1)좌표에서 (3, 3)좌표까지 가는데 드는 최소 에너지는 3+2+3+4+2=14이다.
▣ 입력설명
첫 번째 줄에는 자연수 N(1<=N<=20)이 주어진다.
두 번째 줄부터 계곡의 N*N 격자의 돌다리 높이(10보다 작은 자연수) 정보가 주어진다.
▣ 출력설명
첫 번째 줄에 (1, 1)출발지에서 (N, N)도착지로 가기 위한 최소 에너지를 출력한다.
▣ 입력예제 1
5
3 7 2 1 9
5 8 3 9 2
5 3 1 2 3
5 4 3 2 1
1 7 5 2 4
▣ 출력예제 1
25
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
using namespace std;

int DFS(int, int);
int map[20][20];
int save[20][20];
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cout << DFS(n - 1, n - 1);
	return 0;
}
int DFS(int a, int b) {
	int i = a;
	int j = b;
	if (save[i][j] > 0) return save[i][j];
	if (i == 0 && j == 0) {
		return save[i][j] = map[i][j];
	}
	else {
		if (i == 0) {
			return save[i][j] = DFS(i, j - 1) + map[i][j];
		}
		else if (j == 0) {
			return save[i][j] = DFS(i - 1, j) + map[i][j];
		}
		else {
			return save[i][j] = min(DFS(i - 1, j), DFS(i, j - 1)) + map[i][j];
		}
	}
}

/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];
int DFS(int x, int y){
	if(dy[x][y]>0) return dy[x][y];
	if(x==0 && y==0){
		return arr[0][0];
	}
	else{
		if(y==0) return dy[x][y]=DFS(x-1, y)+arr[x][y];
		else if(x==0) return dy[x][y]=DFS(x, y-1)+arr[x][y];
		else return dy[x][y]=min(DFS(x-1, y), DFS(x, y-1))+arr[x][y];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, cnt=0;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	cnt=DFS(n-1, n-1);
	cout<<cnt;
	return 0;
}
*/

/*
모범 답안 반영 전
	방향을 DP와 같이 순방향(Bottom Up)으로 생각했음.
	효과적으로 DFS+메모이제이션을 구현하려면 역방향(Top Down)으로!

#define INF 2147000000

#include<iostream>
using namespace std;

void DFS(int, int, int);
int map[20][20];
int save[20][20];
int dy[2] = { 0,1 }, dx[2] = { 1,0 };
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			save[i][j] = INF;
		}
	}
	save[0][0] = map[0][0];
	DFS(0, 0, map[0][0]);
	cout << save[n - 1][n - 1];
	return 0;
}
void DFS(int a, int b, int accum) {
	int i = a;
	int j = b;
	int sum = accum;
	for (int k = 0; k < 2; k++) {
		int ii = i + dy[k];
		int jj = j + dx[k];
		if (ii >= n || jj >= n) continue;
		if (save[ii][jj] > sum + map[ii][jj]) {
			save[ii][jj] = sum + map[ii][jj];
			DFS(ii, jj, sum + map[ii][jj]);
		}
	}
}
*/