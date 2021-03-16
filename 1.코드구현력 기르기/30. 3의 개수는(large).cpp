/*
30. 3의 개수는?(large)
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개
있는지 구하려고 합니다.
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
3의 개수는 2개입니다.
자연수 N이 입력되면 1부터 N까지 숫자를 적을 때, 3의 개수가 몇 개인지 구하여 출력하는
프로그램을 작성하세요.
▣ 입력설명
첫 줄에 자연수의 개수 N(3<=N<=1,000,000,000)이 주어집니다.
▣ 출력설명
3의 개수를 출력하세요.
▣ 입력예제 1
15
▣ 출력예제 1
2
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int pre, now, next, digit, cnt = 0;
	string n;
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		digit = pow(10, n.size() - 1 - i);
		if (i != 0) {
			pre = stoi(n.substr(0, i));
			cnt += pre * digit;
		}
		now = n[i] - '0';
		if (i != n.size() - 1) {
			if (now >= 4) cnt += digit;
			else if (now == 3) {
				next = stoi(n.substr(i + 1));
				cnt += (next + 1);
			}
		}
		else {
			if (now >= 3) cnt += digit;
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
	int n, lt=1, rt, cur, k=1, res=0;
	scanf("%d", &n);
	while(lt!=0){
		lt=n/(k*10);
		rt=n%k;
		cur=(n/k)%10;
		if(cur>3) res=res+((lt+1)*k);
		else if(cur==3) res=res+((lt*k)+(rt+1));
		else res=res+(lt*k);
		k=k*10;
	}
	printf("%d\n", res);
	return 0;
}
*/

/*
모범 답안 반영 전
	Case #04만 정답보다 1이 작게 나와 Wrong_answer
*/