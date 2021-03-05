/*
3-2. 돌다리 건너기(Bottom-Up)
철수는 학교에 가는데 개울을 만났습니다. 개울은 N개의 돌로 다리를 만들어 놓았습니다. 철
수는 돌 다리를 건널 때 한 번에 한 칸 또는 두 칸씩 건너뛰면서 돌다리를 건널 수 있습니다.
철수가 개울을 건너는 방법은 몇 가지일까요?
▣ 입력설명
첫째 줄은 돌의 개수인 자연수 N(3≤N≤45)이 주어집니다.
▣ 출력설명
첫 번째 줄에 개울을 건너는 방법의 수를 출력합니다.
▣ 입력예제 1
7
▣ 출력예제 1
34
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int n;
	int dp[47];
	dp[1] = 1;
	dp[2] = 2;
	cin >> n;
	for (int i = 3; i <= n + 1; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[n + 1];
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
	for(int i=3; i<=n+1; i++){
		dy[i]=dy[i-1]+dy[i-2];
	}
	cout<<dy[n+1];
	return 0;
}
*/