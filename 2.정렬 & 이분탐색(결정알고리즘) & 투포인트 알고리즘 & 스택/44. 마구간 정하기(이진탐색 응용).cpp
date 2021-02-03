//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
using namespace std;

/*
44. 마구간 정하기(이분검색 응용)
N개의 마구간이 1차원 수직선상에 있습니다. 각 마구간은 x1, x2, x3, ......, xN의 좌표를 가
지며, 마구간간에 좌표가 중복되는 일은 없습니다.
현수는 C마리의 말을 가지고 있는데, 이 말들은 서로 가까이 있는 것을 좋아하지 않습니다.
각 마구간에는 한 마리의 말만 넣을 수 있고, 가장 가까운 두 말의 거리가 최대가 되게 말을
마구간에 배치하고 싶습니다.
C마리의 말을 N개의 마구간에 배치했을 때 가장 가까운 두 말의 거리가 최대가 되는 그 최대
값을 출력하는 프로그램을 작성하세요.
▣ 입력설명
첫 줄에 자연수 N(3<=N<=200,000)과 C(2<=C<=N)이 공백을 사이에 두고 주어집니다.
둘째 줄부터 N개의 줄에 걸쳐 마구간의 좌표 xi(0<=xi<=1,000,000,000)가 한 줄에 하나씩
주어집니다.
▣ 출력설명
첫 줄에 가장 가까운 두 말의 최대 거리를 출력하세요.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, c, cnt, start, end, mid, min=1000000000, max, res=-1, sub, a, b;
	cin >> n >> c;
	int *pos_arr = new int[n];
	cin >> pos_arr[0];
	for (int i = 1; i < n; i++) {
		cin >> pos_arr[i];
		sub = abs(pos_arr[i-1] - pos_arr[i]);
		if (sub < min) min = sub;
	}
	sort(pos_arr, pos_arr + n);
	max = pos_arr[n - 1] - pos_arr[0];
	start = min;
	end = max;
	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 1;
		a = 0;
		b = 1;
		while (b < n) {
			if (pos_arr[b] - pos_arr[a] >= mid) {
				cnt++;
				a = b;
			}
			b++;
		}
		if (cnt >= c) {
			res = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << res;
	delete[] pos_arr;
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int Count(int len, int x[]){
	int i, cnt=1, pos=x[1];
	for(i=2; i<=n; i++){
		if(x[i]-pos>=len){
			cnt++;
			pos=x[i];
		}
	}
	return cnt;
}
int main(){
	//freopen("input.txt", "rt", stdin);
	int m, i, lt=1, rt, mid, res;
	scanf("%d %d", &n, &m);
	int *x = new int[n+1];
	for(i=1; i<=n; i++){
		scanf("%d", &x[i]);
	}
	sort(x+1, x+n+1);
	rt=x[n];
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(Count(mid, x)>=m){
			res=mid;
			lt=mid+1;
		}
		else rt=mid-1;
	}
	printf("%d\n", res);
	delete[] x;
	return 0;
}
*/