/*
6. 가장 높은 탑 쌓기
밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다. 탑은 벽돌을 한 개씩 아래
에서 위로 쌓으면서 만들어 간다. 아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 프
로그램을 작성하시오. 
(조건1) 벽돌은 회전시킬 수 없다. 즉, 옆면을 밑면으로 사용할 수 없다.
(조건2) 밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
(조건3) 벽돌들의 높이는 같을 수도 있다.
(조건4) 탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
(조건5) 무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.
▣ 입력설명
입력 파일의 첫째 줄에는 입력될 벽돌의 수가 주어진다. 입력으로 주어지는 벽돌의 수는 최대 
100개이다. 둘째 줄부터는 각 줄에 한 개의 벽돌에 관한 정보인 벽돌 밑면의 넓이, 벽돌의 높
이 그리고 무게가 차례대로 양의 정수로 주어진다. 각 벽돌은 입력되는 순서대로 1부터연속적
인 번호를 가진다. 
▣ 출력설명
첫 번째 줄에 가장 높이 쌓을 수 있는 탑의 높이를 출력한다.
▣ 입력예제 1 
5
25 3 4
4 4 6
9 2 3
16 2 5
1 5 2
▣ 출력예제 1
10
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Rock
{
	int size;
	int height;
	int weight;
	Rock(int s, int h, int w) {
		size = s;
		height = h;
		weight = w;
	}
	bool operator<(const Rock &b) const {
		return size > b.size;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	vector<Rock> rockV;
	int dp[100] = { 0 };
	int n, s, h, w, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> h >> w;
		rockV.push_back(Rock(s, h, w));
	}
	sort(rockV.begin(), rockV.end());
	dp[0] = rockV[0].height;
	for (int i = 1; i < n; i++) {
		int max_h = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (rockV[i].weight < rockV[j].weight) {
				if (max_h < dp[j]) max_h = dp[j];
			}
		}
		dp[i] = max_h + rockV[i].height;
		if (res < dp[i]) res = dp[i];
	}
	cout << res;
	return 0;
}

/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
struct Brick{
	int s, h, w;
	Brick(int a, int b, int c){
		s=a, h=b, w=c;
	}
	bool operator<(const Brick &b)const{
		return s>b.s;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, a, b, c, max_h=0, res=0;
	cin>>n;
	vector<Brick> Bricks;
	vector<int> dy(n, 0);
	for(int i=0; i<n; i++){
		cin>>a>>b>>c;
		Bricks.push_back(Brick(a, b, c));
	}
	sort(Bricks.begin(), Bricks.end());
	//for(auto x : Bricks) cout<<x.s<<" "<<x.h<<" "<<x.w<<endl;
	dy[0]=Bricks[0].h;
	res=dy[0];
	for(int i=1; i<n; i++){
		max_h=0;
		for(int j=i-1; j>=0; j--){
			if(Bricks[j].w > Bricks[i].w && dy[j]>max_h){
				max_h=dy[j];
			}
		}
		dy[i]=max_h+Bricks[i].h;
		res=max(res, dy[i]);
	}
	cout<<res;
	return 0;
}
*/