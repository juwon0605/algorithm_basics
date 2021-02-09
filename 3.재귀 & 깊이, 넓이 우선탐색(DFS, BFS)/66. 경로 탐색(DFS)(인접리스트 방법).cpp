//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

/*
66. 경로 탐색(DFS : 인접리스트 방법)
방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력하는 프
로그램을 작성하세요. 아래 그래프에서 1번 정점에서 5번 정점으로 가는 가지 수는
1 2 3 4 5
1 2 5
1 3 4 2 5
1 3 4 5
1 4 2 5
1 4 5
총 6 가지입니다.
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
총 가지수를 출력한다.
*/
void DFS(int);
vector<vector<int>> list(21);
int flag[1025];
int n, cnt = 0;
int main() {
	//freopen("input.txt", "rt", stdin);
	int m, v1, v2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		list[i].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		cin >> v1 >> v2;
		list[v1].push_back(v2);
	}
	flag[1] = 1;
	DFS(1);
	cout << cnt;
	return 0;
}
void DFS(int v) {
	if (v == n) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < list[v].size(); i++) {
			if (flag[list[v][i]] == 0) {
				flag[list[v][i]] = 1;
				DFS(list[v][i]);
				flag[list[v][i]] = 0;
			}
		}
	}
}

/*
모범 답안
#include<stdio.h>
#include<vector>
using namespace std;
int ch[30], cnt=0, n;
vector<int> map[30];
void DFS(int v){
	int i;
	if(v==n){
		cnt++;
	}
	else{
		for(i=0; i<map[v].size(); i++){
			if(ch[map[v][i]]==0){
				ch[map[v][i]]=1;
				DFS(map[v][i]);
				ch[map[v][i]]=0;
			}
		}
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int m, i, a, b;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}
	ch[1]=1;
	DFS(1);
	printf("%d\n", cnt);
	return 0;
}

<경로까지 출력하는 코드>
#include<stdio.h>
#include<vector>
using namespace std;
int ch[30], cnt=0, n, path[30];
vector<int> map[30];
void DFS(int v, int L){
	int i, j;
	if(v==n){
		cnt++;
		for(j=0; j<L; j++){
			printf("%d ", path[j]);
		}
		puts("");
	}
	else{
		for(i=0; i<map[v].size(); i++){
			if(ch[map[v][i]]==0){
				ch[map[v][i]]=1;
				path[L]=map[v][i];
				DFS(map[v][i], L+1);
				ch[map[v][i]]=0;
			}
		}
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int m, i, j, a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}
	ch[1]=1;
	path[0]=1;
	DFS(1, 1);
	printf("%d\n", cnt);
	return 0;
}
*/