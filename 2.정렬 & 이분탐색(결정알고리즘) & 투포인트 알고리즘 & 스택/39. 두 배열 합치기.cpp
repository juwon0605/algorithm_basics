//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
39. 두 배열 합치기
오름차순으로 정렬이 된 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하는 프로그램
을 작성하세요.
▣ 입력설명
첫 번째 줄에 첫 번째 배열의 크기 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 배열 원소가 오름차순으로 주어집니다.
세 번째 줄에 두 번째 배열의 크기 M(1<=M<=100)이 주어집니다.
네 번째 줄에 M개의 배열 원소가 오름차순으로 주어집니다.
각 배열의 원소는 int형 변수의 크기를 넘지 않습니다.
▣ 출력설명
오름차순으로 정렬된 배열을 출력합니다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int a_cnt = 0, b_cnt = 0, res_cnt = 0;
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	int *b = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int *res = new int[n + m];
	while (a_cnt < n && b_cnt < m) {
		if (a[a_cnt] >= b[b_cnt]) {
			res[res_cnt++] = b[b_cnt++];
		}
		else {
			res[res_cnt++] = a[a_cnt++];
		}
	}
	while (a_cnt < n) res[res_cnt++] = a[a_cnt++];
	while (b_cnt < m) res[res_cnt++] = b[b_cnt++];
	for (int i = 0; i < res_cnt; i++) {
		cout << res[i] << " ";
	}
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[101], b[101], c[300];
int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, i, p1=1, p2=1, p3=1;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(i=1; i<=m; i++){
		scanf("%d", &b[i]);
	}
	while(p1<=n && p2<=m){
		if(a[p1]<b[p2]){
			c[p3++]=a[p1++];
		}
		else{
			c[p3++]=b[p2++];
		}
	}
	while(p1<=n) c[p3++]=a[p1++];
	while(p2<=m) c[p3++]=b[p2++];
	for(i=1; i<p3; i++){
		printf("%d ", c[i]);
	}
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	int a_cnt = 0, b_cnt = 0, res_cnt = 0;
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	int *b = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int *res = new int[n + m];
	while (a_cnt < n && b_cnt < m) {
		if (a[a_cnt] >= b[b_cnt]) {
			res[res_cnt] = b[b_cnt];
			b_cnt++;
		}
		else {
			res[res_cnt] = a[a_cnt];
			a_cnt++;
		}
		res_cnt++;
	}
	if (a_cnt == n) {
		for (int i = b_cnt; i < m; i++) {
			res[res_cnt] = b[i];
			res_cnt++;
		}
	}
	else {
		for (int i = a_cnt; i < n; i++) {
			res[res_cnt] = a[i];
			res_cnt++;
		}
	}
	for (int i = 0; i < n + m; i++) {
		cout << res[i] << " ";
	}
	return 0;
}
*/