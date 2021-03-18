// #define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

/*
7. 영어단어 복구
현수의 컴퓨터가 바이러스에 걸려 영어단어가 뛰어쓰기와 대소문자가 혼합되어 표현된다.
예를 들면 아름다운 이란 뜻을 가지고 있는 beautiful 단어가 “bE au T I fu L” 과 같이
컴퓨터에 표시되고 있습니다. 위와 같이 에러로 표시되는 영어단어를 원래의 표현대로 공백을
제거하고 소문자화 시켜 출력하는 프로그램을 작성하세요.
*/

int main() {
	// freopen("input.txt", "rt", stdin);
	string text;
	string correct;
	getline(cin, text);
	for (unsigned int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			correct += text[i];
		}
	}
	for (unsigned int i = 0; i < correct.length(); i++) {
		correct[i] = tolower(correct[i]);
	}
	cout << correct;
}

/*
모범 답안
#include<stdio.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	char a[101], b[101];
	int i, p=0;
	gets(a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]!=' '){
			if(a[i]>=65 && a[i]<=90){
				b[p++]=a[i]+32;
			}
			else b[p++]=a[i];
		}
	}
	b[p]='\0';
	printf("%s\n", b);
	return 0;
}
*/