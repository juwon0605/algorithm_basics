//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

/*
28. N!에서 0의 개수
자연수 N이 입력되면 N! 값에서 일의 자리부터 연속적으로 ‘0’이 몇 개 있는지 구하는 프로그
램을 작성하세요.
만약 5! =  × ×  ×  × = 120으로 일의자리부터 연속적된 ‘0’의 개수는 1입니다.
만약 12! = 479001600으로 일의자리부터 연속적된 ‘0’의 개수는 2입니다.
▣ 입력설명
첫 줄에 자연수 N(10<=N<=1,000)이 입력된다.
▣ 출력설명
일의 자리부터 연속된 0의 개수를 출력합니다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int> cnt_vec(n + 1);
	for (int i = 2; i <= n; i++) {
		int copy = i;
		int j = 2;
		while (copy != 1) {
			if (copy % j == 0) {
				cnt_vec[j]++;
				copy /= j;
			} else j++;
		}
	}
	cout << (cnt_vec[2] > cnt_vec[5] ? cnt_vec[5] : cnt_vec[2]);
	return 0;
}
/*
모범 답안

*/

/*
모범 답안 반영 전

*/