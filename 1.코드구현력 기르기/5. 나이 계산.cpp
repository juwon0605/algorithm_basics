// #define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

/*
5. 나이계산
주민등록증의 번호가 주어지면 주민등록증 주인의 나이와 성별을 판단하여 출력하는 프로그램
을 작성하세요. 주민등록증의 번호는 -를 기준으로 앞자리와 뒷자리로 구분된다.
뒷자리의 첫 번째 수가 1이면 1900년대생 남자이고, 2이면 1900년대생 여자, 3이면 2000년대
생 남자, 4이면 2000년대생 여자이다.
올해는 2019년입니다. 해당 주민등록증 주인의 나이와 성별을 출력하세요.
*/

int main() {
	// freopen("input.txt", "rt", stdin);
	int age;
	string sex;
	string id;
	cin >> id;
	int id_sex = stoi(id.substr(7, 1));
	if ((id_sex == 1) || (id_sex == 3)) {
		sex = "M";
	}
	else {
		sex = "W";
	}
	int id_year = stoi(id.substr(0,2));
	if (id_year >= 20) {
		age = 120 - id_year;
	}
	else {
		if ((id_sex == 1) || (id_sex == 2)) {
			age = 120 - id_year;
		}
		else {
			age = 20 - id_year;
		}
	}
	cout << age << " " << sex;
	return 0;
}

/*
모범 답안
#include<stdio.h>
int main(){
	char a[20];
	int year, age;
	scanf("%s", &a);
	if(a[7]=='1' || a[7]=='2') year=1900+((a[0]-48)*10+(a[1]-48));
	else year=2000+((a[0]-48)*10+(a[1]-48));
	age=2019-year+1;
	printf("%d ", age);
	if(a[7]=='1' || a[7]=='3') printf("M\n");
	else printf("W\n");
	return 0;
}
*/