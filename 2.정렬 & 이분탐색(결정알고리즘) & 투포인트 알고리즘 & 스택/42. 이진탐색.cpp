//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
using namespace std;

/*
42. 이분검색
임의의 N개의 숫자가 입력으로 주어집니다. N개의 수를 오름차순으로 정렬한 다음 N개의 수
중 한 개의 수인 M이 주어지면 이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지 구하는
프로그램을 작성하세요.
▣ 입력설명
첫 줄에 한 줄에 자연수 N(3<=N<=1,000,000)과 M이 주어집니다.
두 번째 줄에 N개의 수가 공백을 사이에 두고 주어집니다.
▣ 출력설명
첫 줄에 정렬 후 M의 값의 위치 번호를 출력한다.
*/
int binary_search(int*, int, int);
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, num;
	cin >> n >> num;
	int *num_arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num_arr[i];
	}
	sort(num_arr, num_arr + n);
	cout <<  binary_search(num_arr, n, num)+1;
	return 0;
}
int binary_search(int* arr, int len, int key) {
	int start = 0;
	int end = len - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}
/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, i, key, lt=0, rt, mid, tmp;
	scanf("%d %d", &n, &key);
	vector<int> a;
	for(i=0; i<n; i++){
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	rt=n-1;
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(a[mid]==key){
			printf("%d\n", mid+1);
			return 0;
		}
		else if(a[mid]>key) rt=mid-1;
		else lt=mid+1;
	}
	return 0;
}
*/