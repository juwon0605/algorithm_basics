﻿/*
13. 회장뽑기(플로이드-워샬 응용)
월드컵축구의 응원을 위한 모임에서 회장을 선출하려고 한다. 이모임은 만들어진지 얼마 되지
않았기 때문에 회원사이에 서로 모르는 사람도 있지만, 몇 사람을 통하면 서로 모두 알 수 있
다.
각 회원은 다른 회원들과 가까운 정도에 따라 점수를 받게 된다.
예를 들어 어느 회원이 다른 모든 회원과 친구이면, 이 회원의 점수는 1점이다. 어느 회원의
점수가 2점이면, 다른 모든 회원이 친구이거나, 친구의 친구임을 말한다. 또한, 어느 회원의
점수가 3점이면, 다른 모든 회원이 친구이거나, 친구의 친구이거나, 친국의 친구의 친구임을
말한다.4점, 5점등은 같은 방법으로 정해진다.
각 회원의 점수를 정할 때 주의할 점은 어떤 두 회원이 친구 사이이면서 동시에 친구의 친구
사이이면, 이 두 사람은 친구사이라고 본다. 회장은 회원들 중에서 점수가 가장 작은 사람이
된다.
회장의 점수와 회장이 될 수 있는 모든 사람을 찾는 프로그램을 작성하시오.
▣ 입력설명
입력의 첫째 줄에는 회원의 수가 있다.
단, 회원의 수는 50명을 넘지 않는다. 둘째 줄 이후로는 한 줄에 두 개의 회원번호가 있는데,
이것은 두 회원이 서로 친구임을 나타낸다. 회원번호는 1부터 회원의 수만큼 번호가 붙어있다.
마지막 줄에는 -1이 두 개 들어있다
▣ 출력설명
첫째 줄은 회장 후보의 점수와 회장후보 수를 출력하고 두 번째 줄은 회장 후보를 모두 출력
한다.
▣ 입력예제 1
5
1 2
2 3
3 4
4 5
2 4
5 3
-1 -1
▣ 출력예제 1
2 3
2 3 4
출처 : 한국정보올림피아드
*/

//#define _CRT_SECURE_NO_WARNINGS
#define INF 2500

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	vector<vector<int>> dp(51, vector<int>(51, INF));
	vector<int> scoreV(51, INF);
	vector<int> resV;
	int n, a, b, score, minimum = INF;
	cin >> n;
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	cin >> a >> b;
	while (!(a == -1 && b == -1)) {
		dp[a][b] = 1;
		dp[b][a] = 1;
		cin >> a >> b;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		score = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] > score) score = dp[i][j];
		}
		scoreV[i] = score;
		if (minimum > score) minimum = score;
	}
	for (int i = 1; i <= n; i++) {
		if (scoreV[i] == minimum) resV.push_back(i);
	}
	cout << minimum << " " << resV.size() << "\n";
	for (int i = 0; i < resV.size(); i++) {
		cout << resV[i] << " ";
	}
	return 0;
}

/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, a, b, score;
	cin>>n;
	vector<vector<int> > dis(n+1, vector<int>(n+1, 100));
	vector<int> res(n+1);
	for(int i=1; i<=n; i++) dis[i][i]=0;
	while(true){
		cin>>a>>b;
		if(a==-1 && b==-1) break;
		dis[a][b]=1;
		dis[b][a]=1;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	score=100;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) continue;
			res[i]=max(res[i], dis[i][j]);
		}
		score=min(score, res[i]);
	}
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(res[i]==score) cnt++;
	}
	cout<<score<<" "<<cnt<<endl;
	for(int i=1; i<=n; i++){
		if(res[i]==score) cout<<i<<" ";
	}
	return 0;
}
*/