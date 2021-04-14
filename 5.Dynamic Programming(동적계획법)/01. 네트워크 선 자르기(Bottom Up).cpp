/*
1. 네트워크 선 자르기(Bottom-Up)
현수는 네트워크 선을 1m, 2m의 길이를 갖는 선으로 자르려고 합니다.
예를 들어 4m의 네트워크 선이 주어진다면
1) 1m+1m+1m+1m
2) 2m+1m+1m
3) 1m+2m+1m
4) 1m+1m+2m
5) 2m+2m
의 5가지 방법을 생각할 수 있습니다. (2)와 (3)과 (4)의 경우 왼쪽을 기준으로 자르는 위치가
다르면 다른 경우로 생각한다.
그렇다면 네트워크 선의 길이가 Nm라면 몇 가지의 자르는 방법을 생각할 수 있나요?
▣ 입력설명
첫째 줄은 네트워크 선의 총 길이인 자연수 N(3≤N≤45)이 주어집니다.
▣ 출력설명
첫 번째 줄에 부분증가수열의 최대 길이를 출력한다.
▣ 입력예제 1
7
▣ 출력예제 1
21
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int n;
	int dp[46] = { 0 };
	dp[1] = 1;
	dp[2] = 2;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[n];
	return 0;
}
/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
int dy[50];
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	cin>>n;
	dy[1]=1;
	dy[2]=2;
	for(int i=3; i<=n; i++){
		dy[i]=dy[i-1]+dy[i-2];
	}
	cout<<dy[n];
	return 0;
}
*/

/*
모범 답안 반영 전
//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

void DFS(int);
int n, res = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	cin >> n;
	DFS(0);
	cout << res;
	return 0;
}
void DFS(int L) {
	if (L == n) {
		res++;
	}
	else {
		DFS(L + 1);
		if (L + 2 <= n) {
			DFS(L + 2);
		}
	}
}
*/