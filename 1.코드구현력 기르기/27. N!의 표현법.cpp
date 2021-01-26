//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

/*
27. N!의 표현법
임의의 N에 대하여 N!은 1부터 N까지의 곱을 의미한다. 이는 N이 커짐에 따라 급격하게 커진
다. 이러한 큰 수를 표현하는 방법으로 소수들의 곱으로 표현하는 방법이 있다. 먼저 소수는
2, 3, 5, 7, 11, 13... 순으로 증가함을 알아야 한다. 예를 들면 825는 (0 1 2 0 1)로 표현이
가능한데, 이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다. 101보
다 작은 임의의 N에 대하여 N 팩토리얼을 이와 같은 표기법으로 변환하는 프로그램을 작성해
보자. 출력은 아래 예제와 같이 하도록 한다.
▣ 입력설명
첫 줄에 자연수 N(3<=N<=1000)이 입력된다.
▣ 출력설명
소수의 곱으로 표현한다.
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
			}
			else j++;
		}
	}
	cout << n << "! = ";
	for (int i = 2; i <= n; i++) {
		if (cnt_vec[i] != 0) cout << cnt_vec[i] << " ";
	}
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, tmp;
	scanf("%d", &n);
	vector<int> ch(n+1);
	for(i=2; i<=n; i++){
		tmp=i;
		j=2;
		while(1){
			if(tmp%j==0){
				ch[j]++;
				tmp=tmp/j;
			}
			else j++;
			if(tmp==1) break;
		}
	}
	printf("%d! = ", n);
	for(j=2; j<=n; j++){
		if(ch[j]!=0) printf("%d ", ch[j]);
	}
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<int> cnt_vec(n + 1);
	vector<int> prime_vec;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j = j + i) {
			cnt_vec[j]++;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (cnt_vec[i] == 1) prime_vec.push_back(i);
	}
	prime_vec.push_back(0);
	cout << n << "! = ";
	int i = 0;
	while (prime_vec[i] != 0) {
		int cnt = 0;
		for (int j = 2; j <= n; j++) {
			int copy = j;
			while (copy%prime_vec[i] == 0) {
				cnt++;
				copy /= prime_vec[i];
			}
		}
		cout << cnt << " ";
		i++;
	}
	return 0;
}
*/