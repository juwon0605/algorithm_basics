//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cmath>
using namespace std;

/*
60. 합이 같은 부분집합(DFS : 아마존 인터뷰)
N개의 원소로 구성된 자연수 집합이 주어지면, 이 집합을 두 개의 부분집합으로 나누었을 때
두 부분집합의 원소의 합이 서로 같은 경우가 존재하면 “YES"를 출력하고, 그렇지 않으면
”NO"를 출력하는 프로그램을 작성하세요.
예를 들어 {1, 3, 5, 6, 7, 10}이 입력되면 {1, 3, 5, 7} = {6, 10} 으로 두 부분집합의 합이
16으로 같은 경우가 존재하는 것을 알 수 있다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=10)이 주어집니다.
두 번째 줄에 집합의 원소 N개가 주어진다. 각 원소는 중복되지 않으며 그 크기는 1,000,000
이하입니다.
▣ 출력설명
첫 번째 줄에 “YES" 또는 ”NO"를 출력한다.
*/
void subset(int, int);
int num_arr[11];
bool flag = false;
int total = 0;
int n;

int main() {
	//freopen("input.txt", "rt", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num_arr[i];
		total += num_arr[i];
	}
	subset(1, 0);
	cout << (flag == true ? "YES" : "NO");
	return 0;
}

void subset(int L, int accum) {
	if (accum > (total / 2)) return;
	if (flag == true) return;
	if (L == n + 1) {
		if (accum == (total - accum)) flag = true;
	}
	else {
		subset(L + 1, accum + num_arr[L]);
		subset(L + 1, accum);
	}
}
/*
모범 답안
#include<stdio.h>
int n, a[11], total=0;
bool flag=false;
void DFS(int L, int sum){
	if(sum>(total/2)) return;
	if(flag==true) return;
	if(L==n+1){
		if(sum==(total-sum)){
			flag=true;
		}
	}
	else{
		DFS(L+1, sum+a[L]);
		DFS(L+1, sum);
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total+=a[i];
	}
	DFS(1, 0);
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
*/

/*
모범 답안 반영 전
void subset(int);
int num_arr[11];
int check_arr[11];
int sum_arr[1025];
int rest_arr[1025];
int n;
int p = 1;
int main() {
	//freopen("input.txt", "rt", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num_arr[i];
	}
	subset(1);
	for (int i = 1; i <= pow(2, n); i++) {
		if (sum_arr[i] == rest_arr[i]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
void subset(int L) {
	if (L == n + 1) {
		int sum = 0;
		int rest = 0;
		for (int i = 1; i <= n; i++) {
			if (check_arr[i] == 1) sum += num_arr[i];
			else rest += num_arr[i];
		}
		sum_arr[p] = sum;
		rest_arr[p] = rest;
		p++;
	}
	else {
		check_arr[L] = 1;
		subset(L + 1);
		check_arr[L] = 0;
		subset(L + 1);
	}
}
*/