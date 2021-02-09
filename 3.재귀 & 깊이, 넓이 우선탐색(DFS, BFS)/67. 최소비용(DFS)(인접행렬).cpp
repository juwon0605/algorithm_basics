//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
67. 최소비용(DFS : 인접행렬)
가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그
램을 작성하세요.
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
총 가지수를 출력한다.
*/
void DFS(int);
int matrix[21][21];
int flag[1025];
int n, min = 2147000000, sum = 0;
int main() {
	//freopen("input.txt", "rt", stdin);
	int m, v1, v2, e;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> v1 >> v2 >> e;
		matrix[v1][v2] = e;
	}
	flag[1] = 1;
	DFS(1);
	cout << min;
	return 0;
}
void DFS(int v) {
	if (v == n) {
		if (min > sum) min = sum;
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (matrix[v][i] > 0 && flag[i] == 0) {
				flag[i] = 1;
				sum += matrix[v][i];
				DFS(i);
				flag[i] = 0;
				sum -= matrix[v][i];
			}
		}
	}
}

/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[30][30], ch[30], n, cost=2147000000;

void DFS(int v, int sum){
	int i;
	if(v==n){
		if(sum<cost) cost=sum;
	}
	else{
		for(i=1; i<=n; i++){
			if(map[v][i]>0 && ch[i]==0){
				ch[i]=1;
				DFS(i, sum+map[v][i]);
				ch[i]=0;
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
		map[a][b]=c;
	}
	ch[1]=1;
	DFS(1, 0);
	printf("%d\n", cost);

	return 0;
}
*/