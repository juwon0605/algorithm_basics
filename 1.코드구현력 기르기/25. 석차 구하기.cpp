//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
25. 석차 구하기
N명의 학생의 수학점수가 입력되면 각 학생의 석차를 입력된 순서대로 출력하는 프로그램을
작성하세요.
▣ 입력설명
첫 줄에 N(1<=N<=100)이 입력되고, 두 번째 줄에 수학점수를 의미하는 N개의 정수가 입력된
다. 같은 점수가 입력될 경우 높은 석차로 동일 처리한다. 즉 가장 높은 점수가 92점인데 92
점이 3명 존재하면 1등이 3명이고 그 다음 학생은 4등이 된다. 점수는 100점 만점이다.
▣ 출력설명
첫 줄에 입력된 순서대로 석차를 출력한다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, num;
	cin >> n;
	int cnt_arr[101] = { 0 };
	int *num_arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num;
		num_arr[i] = num;
		cnt_arr[num]++;
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 100; j > num_arr[i]; j--) {
			cnt += cnt_arr[j];
		}
		cout << cnt << " ";
	}
	return 0;
}
/*
모범 답안
#include<stdio.h>
int main(){
	//freopen("input.txt", "rt", stdin);
	int i, j, a[200], b[200], n;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		b[i]=1;
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(a[j]>a[i]) b[i]++;
		}
	}
	for(i=1; i<=n; i++){
		printf("%d ", b[i]);
	}
	return 0;
}
*/