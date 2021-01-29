//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
32. 선택정렬
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 선택정렬입니다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에
있습니다.
▣ 출력설명
오름차순으로 정렬된 수열을 출력합니다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	int *num_arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num_arr[i];
	}
	for (int i = 0; i < n-1; i++) {
		int min = 100;
		int swap_idx = 0;
		for (int j = i+1; j < n; j++) {
			if (num_arr[j] < min) {
				min = num_arr[j];
				swap_idx = j;
			}
		}
		int temp = num_arr[i];
		num_arr[i] = num_arr[swap_idx];
		num_arr[swap_idx] = temp;
	}
	for (int i = 0; i < n; i++) {
		cout << num_arr[i] << " ";
	}
 	return 0;
}
/*
모범 답안
#include<stdio.h>
int main() {
	freopen("input.txt", "rt", stdin);
	int a[101], n, tmp, idx, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++){
		idx=i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[idx]) idx=j;
		}
		tmp=a[i];
		a[i]=a[idx];
		a[idx]=tmp;
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
*/