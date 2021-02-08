//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
62. 병합정렬
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 병합정렬입니다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에
있습니다.
▣ 출력설명
오름차순으로 정렬된 수열을 출력합니다.
*/
void merge(int, int);
void partition(int, int);
int arr[100];
int temp[100];

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	partition(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		temp[k++] = (arr[i] <= arr[j] ? arr[i++] : arr[j++]);
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= right) temp[k++] = arr[j++];
	for (int i = left; i <= right; i++) {
		arr[i] = temp[i];
	}
}
void partition(int left, int right) {
	if (left >= right) return;
	else {
		int mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[101], tmp[101];
void divide(int lt, int rt){
	int mid;
	int p1, p2, p3;
	if(lt<rt){
		mid=(lt+rt)/2;
		divide(lt, mid);
		divide(mid+1, rt);
		p1=lt;
		p2=mid+1;
		p3=lt;
		while(p1<=mid && p2<=rt){
			if(a[p1]<a[p2]) tmp[p3++]=a[p1++];
			else tmp[p3++]=a[p2++];
		}
		while(p1<=mid) tmp[p3++]=a[p1++];
		while(p2<=rt) tmp[p3++]=a[p2++];
		for(int i=lt; i<=rt; i++){
			a[i]=tmp[i];
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	divide(1, n);
	for(i=1; i<=n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
*/