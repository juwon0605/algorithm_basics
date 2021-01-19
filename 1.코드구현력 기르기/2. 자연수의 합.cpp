#include<iostream>
using namespace std;

/*
2. 자연수의 합
자연수 A, B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요.
*/

int main() {
	int a, b, sum = 0;
	cin >> a >> b;
	for (int i = a; i < b; i++) {
		cout << i << " +";
		sum += i;
	}
	cout << b << " = " << sum + b;
	return 0;
}

/*
모범 답안
#include<iostream>
using namespace std;
int main(){
	int a, b, sum = 0;
	cin >> a >> b;
	for (int i = a; i < b; i++) {
		cout << i << " +";
		sum += i;
	}
	cout << b << " = " << sum+b;
	return 0;
}
*/