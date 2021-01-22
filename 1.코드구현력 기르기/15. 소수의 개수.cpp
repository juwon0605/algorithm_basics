//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

/*
15. 소수의 개수
자연수 N이 입력되면 1부터 N까지의 소수의 개수를 출력하는 프로그램을 작성하세요.
만약 20이 입력되면 1부터 20까지의 소수는 2, 3, 5, 7, 11, 13, 17, 19로 총 8개입니다.
제한시간은 1초입니다.
▣ 입력설명
첫 줄에 자연수의 개수 N(2<=N<=200,000)이 주어집니다.
▣ 출력설명
첫 줄에 소수의 개수를 출력합니다.
*/
int num_arr[200001];
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j = j + i) {
			num_arr[j]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (num_arr[i] == 2) count++;
	}
	cout << count;
	return 0;
}

/*
모범 답안
#include<stdio.h>
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, flag, cnt=0;
	scanf("%d", &n);
	for(i=2; i<=n; i++){
		flag=1;
		for(j=2; j*j<=i; j++){
			if(i%j==0){
				flag=0;
				break;
			}
		}
		if(flag==1) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
*/

/*
모범 답안 반영 전

*/