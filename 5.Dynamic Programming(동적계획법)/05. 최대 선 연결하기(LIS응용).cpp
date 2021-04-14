/*
5. 최대 선 연결하기(LIS응용)
왼쪽의 번호와 오른쪽의 번호가 있는 그림에서 같은 번호끼리 선으로 연결하려고 합니다.
왼쪽번호는 무조건 위에서부터 차례로 1부터 N까지 오름차순으로 나열되어 있습니다.
오른쪽의 번호 정보가 위부터 아래 순서로 주어지만 서로 선이 겹치지 않고 최대 몇 개의 선
을 연결할 수 있는 지 구하는 프로그램을 작성하세요.
1 4
2 1
3 2
4 3
5 9
6 7
7 5
8 6
9 10
10 8
왼쪽 오른쪽
위의 그림은 오른쪽 번호 정보가 4 1 2 3 9 7 5 6 10 8 로 입력되었을 때 선이 서로 겹치지
않고 연결할 수 있는 최대 선을 개수 6을 구한 경우입니다.
▣ 입력설명
첫 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 1부터 N까지의 자연수 N개의 오른쪽 번호 정보가 주어집니다. 순서는 위쪽번호
부터 아래쪽번호 순으로입니다.
▣ 출력설명
첫 줄에 겹치지 않고 그을 수 있는 최대선의 개수를 출력합니다.
▣ 입력예제 1
10
4 1 2 3 9 7 5 6 10 8
▣ 출력예제 1
6
*/

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int n, res = 1;
	int num[101], dp[101];
	cin >> n >> num[1];
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> num[i];
		int max = 0;
		for (int j = i-1; j >= 1; j--) {
			if (num[i] > num[j]) {
				if (dp[j] > max) max = dp[j];
			}
		}
		dp[i] = max + 1;
		if (res < dp[i]) res = dp[i];
	}
	cout << res;
	return 0;
}

/*
모범 답안
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, res=0;
	cin>>n;
	vector<int> arr(n+1), dy(n+1);
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	dy[1]=1;
	for(int i=2; i<=n; i++){
		int max=0;
		for(int j=i-1; j>=1; j--){
			if(arr[j]<arr[i] && dy[j]>max){
				max=dy[j];
			}
		}
		dy[i]=max+1;
		if(dy[i]>res) res=dy[i];
	}
	cout<<res;
	return 0;
}
*/

/*
	NlogN 시간복잡도 풀이법
	priority_queue<pair<int, int>> + struct(2중 배열 정의)를 통한 N(logN)구현
*/