/*
9. 가방문제(냅색 알고리즘)
최고 17kg의 무게를 저장할 수 있는 가방이 있다. 그리고 각각 3kg, 4kg, 7kg, 8kg, 9kg의 
무게를 가진 5종류의 보석이 있다. 이 보석들의 가치는 각각 4, 5, 10, 11, 13이다.
이 보석을 가방에 담는데 17kg를 넘지 않으면서 최대의 가치가 되도록 하려면 어떻게 담아야 
할까요? 각 종류별 보석의 개수는 무한이 많다. 한 종류의 보석을 여러 번 가방에 담을 수 있
다는 뜻입니다.
▣ 입력설명
첫 번째 줄은 보석 종류의 개수와 가방에 담을 수 있는 무게의 한계값이 주어진다.
두 번째 줄부터 각 보석의 무게와 가치가 주어진다.
가방의 저장무게는 1000kg을 넘지 않는다. 보석의 개수는 30개 이내이다.
▣ 출력설명
첫 번째 줄에 가방에 담을 수 있는 보석의 최대가치를 출력한다.
▣ 입력예제 1 
4 11
5 12
3 8
6 14
4 8
▣ 출력예제 1
28
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int dp[1001] = { 0 };
	int n, bagW, w, v;
	cin >> n >> bagW;
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		for (int j = w; j <= bagW; j++) {
			dp[j] = max(dp[j], dp[j-w] + v);
		}
	}
	cout << dp[bagW];
	return 0;
}

/*
모범 답안
	한 보석씩 차례로 누적하며 DP에 적용하기!

#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m, w, v;
	cin>>n>>m;
	vector<int> dy(m+1, 0);
	for(int i=0; i<n; i++){
		cin>>w>>v;
		for(int j=w; j<=m; j++){
			dy[j]=max(dy[j], dy[j-w]+v);
		}
	}
	cout<<dy[m];
	return 0;
}
*/

/*
모범 답안 반영 전
	못 풀었음.
	여러개의 보석을 동시에 어떻게 DP에 적용할지 해결하지 못함.
*/