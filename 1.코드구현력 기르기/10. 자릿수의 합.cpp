﻿//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

/*
10. 자릿수의 합
N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력
하는 프로그램을 작성하세요. 각 자연수의 자릿수의 합을 구하는 함수를 int digit_sum(int x)를
꼭 작성해서 프로그래밍 하세요.
*/
int digit_sum(int);
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	int number;
	int max = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		cin >> number;
		if (max < digit_sum(number)) {
			max = digit_sum(number);
			answer = number;
		} else if (max == digit_sum(number)) {
			if (answer < number) answer = number;
		}
	}
	cout << answer;
	return 0;
}
int digit_sum(int x) {
	int result = 0;
	string str_x = to_string(x);
	for (unsigned int i = 0; i < str_x.size(); i++) {
		result += str_x[i] - '0';
	}
	return result;
}

/*
모범 답안
#include<stdio.h>
int digit_sum(int x){
	int sum=0, tmp;
	while(x>0){
		tmp=x%10;
		sum=sum+tmp;
		x=x/10;
	}
	return sum;
}
int main(){
	freopen("input.txt", "rt", stdin);
	int n, num, i, sum, max=-2147000000, res;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &num);
		sum=digit_sum(num);
		if(sum>max){
			max=sum;
			res=num;
		}
		else if(sum==max){
			if(num>res) res=num;
		}
	}
	printf("%d\n", res);
	return 0;
}
*/