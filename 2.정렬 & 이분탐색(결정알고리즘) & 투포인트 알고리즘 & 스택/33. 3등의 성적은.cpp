//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

/*
33. 3등의 성적은?
N명의 수학성적이 주어지면 그 중 3등을 한 수학성적을 출력하는 프로그램을 작성하세요.
만약 학생의 점수가 100점이 3명, 99점이 2명, 98점이 5명, 97점이 3명 이런식으로 점수가
분포되면 1등은 3명이며, 2등은 2명이며 3등은 5명이 되어 98점이 3등을 한 점수가 됩니다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 수학성적 점수가 공백을 사이에 두고 입력됩니다. 수학성적 점수는 100점
만점 기준으로 입력됩니다.
▣ 출력설명
3등을 한 점수를 출력합니다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	vector<int> cnt_arr(101);
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cnt_arr[num]++;
	}
	int cnt = 0;
	for (int i = 100; i >= 0; i--) {
		if (cnt_arr[i] != 0) cnt++;
		if (cnt == 3) {
			cout << i;
			break;
		}
	}
 	return 0;
}
/*
모범 답안
#include<stdio.h>
int main() {
	freopen("input.txt", "rt", stdin);
	int a[101], n, tmp, idx, i, j, cnt=0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++){
		idx=i;
		for(j=i+1; j<n; j++){
			if(a[j]>a[idx]) idx=j;
		}
		tmp=a[i];
		a[i]=a[idx];
		a[idx]=tmp;
	}
	for(i=1; i<n; i++){
		if(a[i-1]!=a[i]) cnt++;
		if(cnt==2){
			printf("%d\n", a[i]);
			break;
		}
	}
	return 0;
}
*/