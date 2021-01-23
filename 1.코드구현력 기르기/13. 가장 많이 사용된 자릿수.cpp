// #define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

/*
13. 가장 많이 사용된 자릿수
N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력하는 프
로그램을 작성하세요.
예를 들어 1230565625라는 자연수가 입력되면 5가 3번 상용되어 가장 많이 사용된 숫자입니
다. 답이 여러 개일 경우 그 중 가장 큰 수를 출력하세요.
▣ 입력설명
첫 줄에 자연수가 입력됩니다. 자연수의 길이는 100을 넘지 않습니다.
▣ 출력설명
자릿수의 곱을 출력합니다.
*/

int main() {
	// freopen("input.txt", "rt", stdin);
	string n;
	cin >> n;
	int num_arr[10] = { 0 };
	int answer = 0;
	for (int i = 0; i < n.length(); i++) {
		num_arr[n[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (num_arr[answer] <= num_arr[i]) answer = i;
	}
	cout << answer;
	return 0;
}
/*
모범 답안
#include<stdio.h>
int ch[10];
int main(){
	//freopen("input.txt", "rt", stdin);
	int i, digit, max=-2147000000, res;
	char a[101];
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		digit=a[i]-48;
		ch[digit]++;
	}
	for(i=0; i<=9; i++){
		if(ch[i]>=max){
			max=ch[i];
			res=i;
		}
	}
	printf("%d\n", res);
	return 0;
}
*/