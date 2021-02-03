//#define _CRT_SECURE_NO_WARNINGS
#define N 9

#include<iostream>
using namespace std;

/*
48. 각 행의 평균과 가장 가까운 값
<그림 1>과 같이 9 × 9 격자판에 쓰여진 81개의 자연수가 주어질 때, 각 행의 평균을 구하고,
그 평균과 가장 가까운 값을 출력하는 프로그램을 작성하세요. 평균은 소수점 첫 째 자리에서 반
올림합니다. 평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.
▣ 입력설명
첫 째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 자연수가 주어진다. 주어지는 자연수는 100보
다 작다.
▣ 출력설명
첫째 줄에 첫 번째 줄부터 각 줄에 각행의 평균과 그 행에서 평균과 가장 가까운 수를 출력한다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int sum, avg, min, sub, idx;
	int *num_arr = new int[N];
	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < N; j++) {
			cin >> num_arr[j];
			sum += num_arr[j];
		}
		avg = ((sum * 10) / 9 + 5) / 10;
		idx = 0;
		min = abs(avg - num_arr[0]);
		for (int j = 1; j < N; j++) {
			sub = abs(avg - num_arr[j]);
			if (min > sub) {
				min = sub;
				idx = j;
			}
			else if (min == sub) {
				if (num_arr[j] > num_arr[idx]) idx = j;
			}
		}
		cout << avg << " " << num_arr[idx] << endl;
	}
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[10][10];
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, j, sum, ave, min, res, tmp;
	for(i=1; i<=9; i++){
		sum=0;
		for(j=1; j<=9; j++){
			scanf("%d", &a[i][j]);
			sum=sum+a[i][j];
		}
		ave=(sum/9.0)+0.5;
		printf("%d ", ave);
		min=2147000000;
		for(j=1; j<=9; j++){
			tmp=abs(a[i][j]-ave);
			if(tmp<min){
				min=tmp;
				res=a[i][j];
			}
			else if(tmp==min){
				if(a[i][j]>res) res=a[i][j];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
*/