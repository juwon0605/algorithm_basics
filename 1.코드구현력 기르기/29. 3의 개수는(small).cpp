//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

/*
29. 3의 개수는?(small)
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개
있는지 구하려고 합니다.
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
3의 개수는 2개입니다.
자연수 N이 입력되면 1부터 N까지 숫자를 적을 때, 3의 개수가 몇 개인지 구하여 출력하는
프로그램을 작성하세요.
▣ 입력설명
첫 줄에 자연수의 개수 N(3<=N<=100,000)이 주어집니다.
▣ 출력설명
3의 개수를 출력하세요.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string str_num = to_string(i);
		for (int j = 0; j < str_num.length(); j++) {
			if (str_num[j] == '3') cnt++;
		}
	}
	cout << cnt;
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, tmp, i, cnt=0, digit;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		tmp=i;
		while(tmp>0){
			digit=tmp%10;
			if(digit==3) cnt++;
			tmp=tmp/10;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
*/

/*
모범 답안 반영 전

*/