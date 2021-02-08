//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

/*
59. 부분집합(DFS)
자연수 N이 주어지면 1부터 N까지의 원소를 갖는 집합의 부분집합을 모두 출력하는 프로그램
을 작성하세요.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=10)이 주어집니다.
▣ 출력설명
첫 번째 줄부터 각각의 부분집합을 출력합니다. 부분집합을 출력하는 순서는 출력예제에서 출
력한 순서와 같게 합니다. 단 공집합은 출력하지 않습니다.
*/
void subset(int);
int arr[11];
int n;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin >> n;
	subset(1);
	return 0;
}

void subset(int L) {
	if (L == n + 1) {
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 1) cout << i << " ";
		}
		cout << endl;
	}
	else {
		arr[L] = 1;
		subset(L + 1);
		arr[L] = 0;
		subset(L + 1);
	}
}
/*
모범 답안
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, ch[100];
void DFS(int L){
	int i;
	if(L==n+1){
		for(i=1; i<=n; i++){
			if(ch[i]==1) printf("%d ", i);
		}
		puts("");
	}
	else{
		ch[L]=1;
		DFS(L+1);
		ch[L]=0;
		DFS(L+1);
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	DFS(1);
	return 0;
}
*/

/*
모범 답안 반영 전
	못 풀었음.
*/