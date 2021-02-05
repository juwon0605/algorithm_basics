//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
53. K진수 출력
10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 스택 자료구조를 사
용하시기 바랍니다.
▣ 입력설명
첫 번째 줄에 10진수 N(10<=N<=1,000)과 K(2, 5, 8, 16)가 주어진다.
▣ 출력설명
K진수를 출력한다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, k;
	stack<int> stack;
	string str = "0123456789ABCDEF";
	cin >> n >> k;
	while (n > 0) {
		stack.push(n%k);
		n /= k;
	}
	while (!stack.empty()) {
		cout << str[stack.top()];
		stack.pop();
	}
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, k;
	stack<int> s;
	char str[20]="0123456789ABCDEF";
	scanf("%d %d", &n, &k);
	while(n>0){
		s.push(n%k);
		n=n/k;
	}
	while(!s.empty()){
		printf("%c", str[s.top()]);
		s.pop();
	}
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, k;
	stack<int> stack;
	cin >> n >> k;
	while (n > 0) {
		stack.push(n%k);
		n /= k;
	}
	while (!stack.empty()) {
		if (k != 16) {
			cout << stack.top();
			stack.pop();
		}
		else {
			if (stack.top() < 10) {
				cout << stack.top();
			}
			else {
				if (stack.top() == 10) cout << "A";
				else if (stack.top() == 11) cout << "B";
				else if (stack.top() == 12) cout << "C";
				else if (stack.top() == 13) cout << "D";
				else if (stack.top() == 14) cout << "E";
				else if (stack.top() == 15) cout << "F";
			}
			stack.pop();
		}
	}
	return 0;
}
*/