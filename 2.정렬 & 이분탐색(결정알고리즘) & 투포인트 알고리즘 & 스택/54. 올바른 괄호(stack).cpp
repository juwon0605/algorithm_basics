//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
54. 올바른 괄호(stack)
괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.
▣ 입력설명
첫 번째 줄에 괄호 문자열이 입력됩니다. 문자열의 최대 길이는 30이다.
▣ 출력설명
첫 번째 줄에 YES, NO를 출력한다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	string input;
	stack<char> stack;
	getline(cin, input);
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			stack.push('(');
		}
		else {
			if (stack.empty()) {
				cout << "NO";
				return 0;
			}
			else stack.pop();
		}
	}
	cout << (stack.empty() ? "YES" : "NO");
	return 0;
}
/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	stack<char> s;
	string str;
	cin>>str;
	for(auto x : str){
		if(x=='(') s.push(x);
		else{
			if(s.empty() || s.top()!='('){
				cout<<"NO";
				return 0;
			}
			s.pop();
		}
	}
	if(s.empty()) cout<<"YES";
	else cout<<"NO";
	return 0;
}
*/