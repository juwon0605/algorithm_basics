//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

/*
12. 숫자의 총 개수(large)
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
총 21개가 쓰였음을 알 수 있습니다.
자연수 N이 입력되면 1부터 N까지 각 숫자는 몇 개가 사용되었는지를 구하는 프로그램을 작
성하세요.
▣ 입력설명
첫 번째 줄에는 자연수 N(3<=N<=100,000,000)이 주어진다.
▣ 출력설명
첫 번째 줄에 숫자의 총개수를 출력한다.
*/

int main() {
	//freopen("input.txt", "rt", stdin);
	string n;
	int answer = 0;
	cin >> n;
	int digit = n.length();
	for (int i = 1; i < digit; i++) {
		answer += i * 9 * pow(10, i - 1);
	}
	answer += digit * (stoi(n) - (pow(10, digit - 1)) + 1);
	cout << answer;
	return 0;
}
/*
모범 답안
#include<stdio.h>
int main(){
	freopen("input.txt", "rt", stdin);
	int n, sum=0, cnt=1, digit=9, res=0;
	scanf("%d", &n);
	while(sum+digit<n){
		sum=sum+digit;
		res=res+(cnt*digit);
		cnt++;
		digit=digit*10;
	}
	res=res+((n-sum)*cnt);
	printf("%d\n", res);
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	string n;
	int answer = 0;
	cin >> n;
	int digit = n.length();
	for (int i = 1; i < digit; i++) {
		answer += i * 9 * pow(10, i-1);
	}
	// 빼기를 사용해서 두 줄을 한 줄로 더 간단하게 표현 가능!
	answer += digit * ((n[0] - '0') - 1) * pow(10, digit - 1);
	answer += digit * (stoi(n.substr(1, n.length()-1)) + 1);
	cout << answer;
	return 0;
}
*/