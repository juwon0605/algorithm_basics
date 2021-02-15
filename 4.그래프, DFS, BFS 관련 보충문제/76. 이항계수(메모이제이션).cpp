//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
76. 이항계수(메모이제이션)
이항계수는 N개의 원소를 가지는 집합에서 R개의 원소를 뽑아 부분집합을 만드는 경우의 수
를 의미한다. 공식은 
 로 표현된다.
N과 R이 주어지면 이항계수를 구하는 프로그램을 작성하세요.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=20)과 R(0<=R<=20)이 주어진다. 단 (N>=R)
▣ 출력설명
첫 번째 줄에 이항계수 값을 출력한다.
*/
int Factorial(int);
int Combination(int, int);
int d_arr[21][21];
int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n, r, res = 1;
	cin >> n >> r;
	Combination(n, r);
	cout << d_arr[n][r];
	return 0;
}
int Factorial(int n) {
	if (n == 1) return 1;
	else return n * Factorial(n - 1);
}
int Combination(int n, int r) {
	if (d_arr[n][r] != 0) return d_arr[n][r];
	if (r == 0 || n == r) return 1;
	else {
		d_arr[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r);
		return d_arr[n][r];
	}
}
/*
모범 답안
#include<stdio.h>
using namespace std;
int dy[21][21];

int C(int n, int r){
	if(dy[n][r]>0) return dy[n][r];
	if(n==r || r==0) return 1;
	else return dy[n][r]=C(n-1, r)+C(n-1, r-1);
}

int main(){
	freopen("input.txt", "rt", stdin);
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d\n", C(n, r));
	return 0;
}
*/

/*
모범 답안 반영 전

*/