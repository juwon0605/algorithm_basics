//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
57. 재귀함수 이진수 출력
10진수 N이 입력되면 2진수로 변환하여 출력하는 프로그램을 작성하세요. 단 재귀함수를 이용
해서 출력해야 합니다.
▣ 입력설명
첫 번째 줄에 10진수 N(1<=N<=1,000)이 주어집니다.
▣ 출력설명
첫 번째 줄에 이진수를 출력하세요.
*/
void recursion(int);
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	recursion(n);
	return 0;
}
void recursion(int n) {
	if (n == 0) return;
	else {
		recursion(n / 2);
		cout << n % 2;
	}
}

/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void D(int x){
	if(x==0) return;
	else{
		D(x/2);
		printf("%d", x%2);
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	D(n);
	return 0;
}
*/