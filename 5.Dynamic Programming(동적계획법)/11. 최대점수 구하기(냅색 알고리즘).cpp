/*
11. 최대점수 구하기(냅색 알고리즘)
이번 정보올림피아드대회에서 좋은 성적을 내기 위하여 현수는 선생님이 주신 N개의 문제를
풀려고 합니다. 각 문제는 그것을 풀었을 때 얻는 점수와 푸는데 걸리는 시간이 주어지게 됩
니다. 제한시간 M안에 N개의 문제 중 최대점수를 얻을 수 있도록 해야 합니다. (해당문제는
해당시간이 걸리면 푸는 걸로 간주한다, 한 유형당 한개만 풀 수 있습니다.)
▣ 입력설명
첫 번째 줄에 문제의 개수N(1<=N<=100)과 제한 시간 M(10<=M<=1000)이 주어집니다.
두 번째 줄부터 N줄에 걸쳐 문제를 풀었을 때의 점수와 푸는데 걸리는 시간이 주어집니다.
▣ 출력설명
첫 번째 줄에 제한 시간안에 얻을 수 있는 최대 점수를 출력합니다.
▣ 입력예제 1
5 20
10 5
25 12
15 8
6 3
7 4
▣ 출력예제 1
41
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int dp[1001] = { 0 };
	int n, m, score, time;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> score >> time;
		for (int j = m; j >= time; j--) {
			dp[j] = max(dp[j], score + dp[j - time]);
		}
	}
	cout << dp[m];
	return 0;
}

/*
모범 답안1
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt", "rt", stdin);
	ios::sync_with_stdio(false);
	int n, m, ps, pt;
	cin>>n>>m;
	vector<int> dy(m+1);
	for(int i=0; i<n; i++){
		cin>>ps>>pt;
		for(int j=m; j>=pt; j--){
			dy[j]=max(dy[j], dy[j-pt]+ps);
		}			
	}
	cout<<dy[m]<<"\n";		
	return 0;
}
*/

/*
모범 답안2
	재귀로도 풀었음! (11-2)
	0-1 냅색의 경우, W이 매.우. 크다면 재귀+메모이제이션이 더 최적화
	(W = 100,000인 경우는 냅색이 훨씬 빨랐음!)
	시간복잡도: O(2^N)+메모이제이션 VS O(NW)
*/

/*
모범 답안 반영 전
	(중요)
	0-1 냅색의 경우에도 dp를 역순으로 진행하면 1차원 배열로 표현 가능!
	메모리 대폭 감소!
	(실제로는 연산 속도도 대폭 개선!)

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int dp[101][1001];
	int n, m, score, time;
	cin >> n >> m;
	for (int i = 0; i <= m; i++) dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> score >> time;
		for (int j = 0; j <= m; j++) {
			if (j < time) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], score + dp[i - 1][j - time]);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}
*/