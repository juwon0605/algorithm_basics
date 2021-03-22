/*
10. 동전교환
다음과 같이 여러 단위의 동전들이 주어져 있을때 거스름돈을 가장 적은 수의 동전으로 교환
해주려면 어떻게 주면 되는가? 각 단위의 동전은 무한정 쓸 수 있다.
▣ 입력설명
첫 번째 줄에는 동전의 종류개수 N(1<=N<=12)이 주어진다. 두 번째 줄에는 N개의 동전의 종
류가 주어지고, 그 다음줄에 거슬러 줄 금액 M(1<=M<=500)이 주어진다.
각 동전의 종류는 100원을 넘지 않는다.
▣ 출력설명
첫 번째 줄에 거슬러 줄 동전의 최소개수를 출력한다.
▣ 입력예제 1
3
1 2 5
15
▣ 출력예제 1
3
*/

//#define _CRT_SECURE_NO_WARNINGS
#define INF 2147000000

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	vector<int> coinV;
	int dp[501];
	int n, m, coin;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coin;
		coinV.push_back(coin);
	}
	cin >> m;
	dp[0] = 0;
	for (int i = 1; i <= m; i++) dp[i] = INF;
	for (int i = 0; i < coinV.size(); i++) {
		coin = coinV[i];
		for (int j = coin; j <= m; j++) {
			dp[j] = min(dp[j], dp[j - coin] + 1);
		}
	}
	cout << dp[m];
	return 0;
}

/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m;
	cin>>n;
	vector<int> coin(n);
	for(int i=0; i<n; i++) cin>>coin[i];
	cin>>m;
	vector<int> dy(m+1, 1000);
	dy[0]=0;
	for(int i=0; i<n; i++){
		for(int j=coin[i]; j<=m; j++){
			dy[j]=min(dy[j], dy[j-coin[i]]+1);
		}
	}
	cout<<dy[m];
	return 0;
}
*/

/*
모범 답안 반영 전
	(주의)
	ind dp[501] = { INF };
	제일 첫번째 인덱스만 INF로 초기화되고 나머지는 0으로 초기화 됨!
	(dp[0] = INF && dp[1~500] = 0)
*/