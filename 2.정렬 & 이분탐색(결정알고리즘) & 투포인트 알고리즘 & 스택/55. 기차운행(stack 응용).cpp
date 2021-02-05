//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
55. 기차운행(stack 응용)
A도시에서 출발한 기차는 B도시로 도착한다. 그런데 도로 중간에 T자형 교차로가 있어 출발한
기차의 도착 순서를 조정할 수 있다.
A도시					B도시
			교차로
교차로에서는 다음과 같은 두 개의 작업을 합니다.
P(push)작업 : A도시에서 오는 기차를 교차로에 넣는다.
O(out)작업 : 교차로에 들어온 가장 최근 기차를 B도시로 보낸다.
만약 2 1 3 기차 번호 순으로 A도시에서 출발하더라도 B도시에는 T교차로를 이용하여 1 2 3
순으로 도착하게 할 수 있습니다.
그 작업 P, P, O, O, P, O순으로 작업을 하면 B도시에 1, 2, 3 순으로 도착합니다.
1부터 N까지 번호를 가진 기차가 A도시에서 어떤 순으로 출발하든, B도시에 번호순으로 도착
하도록 하는 교차로 작업을 출력합니다. 모든 기차는 교차로에 들어가야만 B도시로 갈 수 있
습니다. 번호순서대로 도착이 불가능하면 impossible 이라고 출력합니다.
▣ 입력설명
첫 번째 줄에 자연수 N(3<=N<=30)가 주어진다.
두 번째 줄에 A도시에서 출발하는 기차번호순이 차례대로 입력된다.
▣ 출력설명
교차로 작업을 순서대로 P와 O로 출력한다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, cur, next = 1;
	stack<int> stack;
	string res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		stack.push(cur);
		res += 'P';
		while (!stack.empty()) {
			if (stack.top() == next) {
				stack.pop();
				res += 'O';
				next++;
			}
			else break;
		}
	}
	cout << (stack.empty() ? res : "impossible");
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	stack<int> s;
	int i, j=1, n, m;
	scanf("%d", &n);
	vector<char> str;
	for(i=1; i<=n; i++){
		scanf("%d", &m);
		s.push(m);
		str.push_back('P');
		while(1){
			if(s.empty()) break;
			if(j==s.top()){
				s.pop();
				j++;
				str.push_back('O');
			}
			else break;
		}
	}
	if(!s.empty()) printf("impossible\n");
	else{
		for(i=0; i<str.size(); i++) printf("%c", str[i]);
	}
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, cur, arrive, next=1;
	stack<int> stack;
	string res;
	cin >> n;
	cin >> cur;
	stack.push(cur);
	res += 'P';
	for (int i = 1; i < n; i++) {
		cin >> cur;
		if (cur < stack.top()) {
			stack.push(cur);
			res += 'P';
		}
		else {
			while (!stack.empty() && cur > stack.top()) {
				arrive = stack.top();
				stack.pop();
				res += 'O';
				if (arrive != next++) {
					cout << "impossible";
					return 0;
				}
			}
			stack.push(cur);
			res += 'P';
		}
	}
	while (!stack.empty()) {
		stack.pop();
		res += 'O';
	}
	cout << res;
	return 0;
}
*/