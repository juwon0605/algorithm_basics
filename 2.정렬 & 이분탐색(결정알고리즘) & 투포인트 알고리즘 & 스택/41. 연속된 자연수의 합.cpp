//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
41. 연속된 자연수의 합
입력으로 양의 정수 N이 입력되면 2개 이상의 연속된 자연수의 합으로 정수 N을 표현하는 방
법의 가짓수를 출력하는 프로그램을 작성하세요.
만약 N=15이면
7+8=15
4+5+6=15
1+2+3+4+5=15
와 같이 총 3가지의 경우가 존재한다.
▣ 입력설명
첫 번째 줄에 양의 정수 N(7<=N<1000)이 주어진다.
▣ 출력설명
첫줄부터 각각의 경우의 수를 출력한다.
맨 마지막 줄에 총 개수를 출력한다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i, copy, k = 1, cnt = 0;
	cin >> n;
	copy = n;
	copy -= k;
	while (copy > 0) {
		k++;
		copy -= k;
		if (copy%k == 0) {
			for (i = 1; i < k; i++) {
				cout << (copy / k) + i << " + ";
			}
			cout << copy / k + i << " = " << n << endl;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
/*
모범 답안
#include<stdio.h>
int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int a, b=1, cnt=0, tmp, i;
	scanf("%d", &a);
	tmp=a;
	a--;
	while(a>0){
		b++;
		a=a-b;
		if(a%b==0){
			for(i=1; i<b; i++){
				printf("%d + ", (a/b)+i);
			}
			printf("%d = %d\n", (a/b)+i, tmp);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i, j, k, add=1, cnt=0; // i=갯수, j=처음자연수, i*j+add=n
	cin >> n;
	for (i = 2; i + add <= n; i++) {
		for (j = 1; i*j + add <= n; j++) {
			if (i*j + add == n) {
				for (k = 0; k < i - 1; k++) {
					cout << j + k << " + ";
				}
				cout << j + k << " = " << n << endl;
				cnt++;
			}
		}
		add += i;
	}
	cout << cnt;
	return 0;
}
*/