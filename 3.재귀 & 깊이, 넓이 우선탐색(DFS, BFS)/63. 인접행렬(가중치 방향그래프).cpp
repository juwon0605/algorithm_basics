//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

/*
63. 인접행렬(가중치 방향그래프)
아래 그림과 같은 그래프 정보를 인접행렬로 표현해보세요.
 
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보와 거리비용이 주어진다.
▣ 출력설명
인접행렬을 출력하세요
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, i, j, e;
	cin >> n >> m;
	vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
	for (int k = 0; k < m; k++) {
		cin >> i >> j >> e;
		matrix[i][j] = e;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[21][21];
int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, a, b, c, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a ,&b, &c);
		map[a][b]=c;
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/