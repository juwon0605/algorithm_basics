//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
49. 블록의 최댓값
현수는 블록놀이를 좋아합니다. 현수에게 정면에서 본 단면과 오른쪽 측면에서 본 단면을 주
고 최대 블록개수를 사용하여 정면과 오른쪽 측면에서 본 모습으로 블록을 쌓으라 했습니다.
현수가 블록을 쌓는데 사용해야 할 최대 개수를 출력하는 프로그램을 작성하세요.
정면

오른쪽 측면

2 3 1
2 2 1
1 1 1
1 1 1
위에서 본 높이(최대개수)

위에서 봤을 때 각 칸의 블록의 개수입니다. 정면에서의 높이 정보와 오른쪽 측면에서의 높이
정보가 주어지면 사용할 수 있는 블록의 쵀대 개수를 출력하세요.
▣ 입력설명
첫 줄에 블록의 크기 N(3<=N<=10)이 주어집니다. 블록이 크기는 정사각형 N*N입니다.
두 번째 줄에 N개의 정면에서의 높이 정보가 왼쪽 정보부터 주어집니다.
세 번째 줄에 N개의 오른쪽 측면 높이 정보가 앞쪽부터 주어집니다.
블록의 높이는 10 미만입니다.
▣ 출력설명
첫 줄에 블록의 최대 개수를 출력합니다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, sum=0;
	cin >> n;
	int *x = new int[n];
	int *y = new int[n];
	int **d_arr = new int*[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[n-1-i];
	}
	for (int i = 0; i < n; i++) {
		d_arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			d_arr[i][j] = (y[i] > x[j] ? x[j] : y[i]);
			sum += d_arr[i][j];
		}
	}
	cout << sum;
	return 0;
}
/*
모범 답안
#include<stdio.h>
int a[11][11], b[11];
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, sum=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		scanf("%d", &b[i]);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			a[j][i]=b[i];
		}
	}
	for(i=n; i>=1; i--)
		scanf("%d", &b[i]);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(a[i][j]>b[i]) a[i][j]=b[i];
		}
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			sum+=a[i][j];
		}
	}
	printf("%d\n", sum);
	return 0;
}
*/