﻿/*
7. 알리바바와 40인의 도둑(Bottom-Up)
알리바바는 40인의 도둑으로부터 금화를 훔쳐 도망치고 있습니다.
알리바바는 도망치는 길에 평소에 잘 가지 않던 계곡의 돌다리로 도망가고자 한다.
계곡의 돌다리는 N×N개의 돌들로 구성되어 있다. 각 돌다리들은 높이가 서로 다릅니다.
해당 돌다리를 건널때 돌의 높이 만큼 에너지가 소비됩니다. 이동은 최단거리 이동을 합니다.
즉 현재 지점에서 오른쪽 또는 아래쪽으로만 이동해야 합니다.
N*N의 계곡의 돌다리 격자정보가 주어지면 (1, 1)격자에서 (N, N)까지 가는데 드는 에너지의
최소량을 구하는 프로그램을 작성하세요.
만약 N=3이고, 계곡의 돌다리 격자 정보가 다음과 같다면
3 3 5
2 3 4
6 5 2
(1, 1)좌표에서 (3, 3)좌표까지 가는데 드는 최소 에너지는 3+2+3+4+2=14이다.
▣ 입력설명
첫 번째 줄에는 자연수 N(1<=N<=20)이 주어진다.
두 번째 줄부터 계곡의 N*N 격자의 돌다리 높이(10보다 작은 자연수) 정보가 주어진다.
▣ 출력설명
첫 번째 줄에 (1, 1)출발지에서 (N, N)도착지로 가기 위한 최소 에너지를 출력한다.
▣ 입력예제 1
5
3 7 2 1 9
5 8 3 9 2
5 3 1 2 3
5 4 3 2 1
1 7 5 2 4
▣ 출력예제 1
25
*/

#define _CRT_SECURE_NO_WARNINGS
#define INF 2147000000

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int map[21][21];
	int dp[21][21];
	int n;
	cin >> n;
	dp[0][1] = 0;
	dp[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		dp[0][i] = INF;
		dp[i][0] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			int small = min(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = small + map[i][j];
		}
	}
	cout << dp[n][n];
	return 0;
}

/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, cnt=0;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	dy[0][0]=arr[0][0];
	for(int i=1; i<n; i++){
		dy[0][i]=dy[0][i-1]+arr[0][i];
		dy[i][0]=dy[i-1][0]+arr[i][0];
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			dy[i][j]=min(dy[i-1][j], dy[i][j-1])+arr[i][j];
		}
	}
	cout<<dy[n-1][n-1];
	return 0;
}
*/