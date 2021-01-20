//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
using namespace std;

/*
8. 올바른 괄호
괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.
*/

int main() {
	//freopen("input.txt", "rt", stdin);
	string text;
	stack<char> judge;
	getline(cin, text);
	if (text[0] == ')') {
		cout << "NO";
		return 0;
	} 
	for (unsigned int i = 0; i < text.size(); i++) {
		if (text[i] == '(') judge.push(text[i]);
		else {
			if (judge.size() == 0) {
				cout << "NO";
				return 0;
			}
			else {
				judge.pop();
			}
		}
	}
	if (judge.size() == 0) cout << "YES";
	else cout << "NO";
	return 0;
}

/*
모범 답안
#include<stdio.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	char a[100];
	int i, cnt=0;
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]=='(') cnt++;
		else if(a[i]==')') cnt--;
		if(cnt<0) break;
	}
	if(cnt==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
*/