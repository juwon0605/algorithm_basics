//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
22. 온도의 최대값
매일 아침 9시에 학교에서 측정한 온도가 어떤 정수의 수열로 주어졌을 때, 연속적인 며칠
동안의 온도의 합이 가장 큰 값을 알아보고자 한다.
예를 들어, 다음과 같이 10일 간의 온도가 주어졌을 때, 3 -2 -4 -9 0 3 7 13 8 -3 모든
연속적인 이틀간의 온도의 합은 다음과 같다.
이때, 온도의 합이 가장 큰 값은 21이다.
매일 측정한 온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰
값을 계산하는 프로그램을 작성하시오.
▣ 입력설명
첫째 줄에는 두 개의 정수 N과 K가 한 개의 공백을 사이에 두고 순서대로 주어진다. 첫 번째
정수 N은 온도를 측정한 전체 날짜의 수이다. N은 2 이상 100,000 이하이다. 두 번째 정수 K
는 합을 구하기 위한 연속적인 날짜의 수이다. K는 1과 N 사이의 정수이다. 둘째 줄에는 매일
측정한 온도를 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 -100
이상 100 이하이다.
▣ 출력설명
첫째 줄에는 온도의 수열에서 연속적인 K일의 온도의 합이 최대가 되는 값을 출력한다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, k;
	int sum = 0;
	cin >> n >> k;
	int *temp_arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp_arr[i];
	}
	for (int i = 0; i < k; i++) {
		sum += temp_arr[i];
	}
	int	max = sum;
	for (int i = k; i < n; i++) {
		sum = sum + temp_arr[i] - temp_arr[i - k];
		if (max < sum) max = sum;
	}
	cout << max;
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, k, i, sum=0, res;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<k; i++){
		sum=sum+a[i];
	}
	res=sum;
	for(i=k; i<n; i++){
		sum=sum+(a[i]-a[i-k]);
		if(sum>res) res=sum;
	}
	printf("%d\n", res);
	return 0;
*/

/*
모범 답안 반영 전
int temp_arr[100000];
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, k, temp;
	cin >> n >> k;
	for (int i = 0; i < k - 1; i++) {
		cin >> temp;
		for (int j = 0; j < i + 1; j++) {
			temp_arr[i - j] += temp;
		}
	}
	for (int i = k - 1; i < n - k + 1; i++) {
		cin >> temp;
		for (int j = 0; j < k; j++) {
			temp_arr[i - j] += temp;
		}
	}
	for (int i = n - k + 1; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < n - i; j++) {
			temp_arr[n - k - j] += temp;
		}
	}
	int max = temp_arr[0];
	for (int i = 1; i < n - k + 1; i++) {
		if (max < temp_arr[i]) max = temp_arr[i];
	}
	cout << max;
	return 0;
}
*/