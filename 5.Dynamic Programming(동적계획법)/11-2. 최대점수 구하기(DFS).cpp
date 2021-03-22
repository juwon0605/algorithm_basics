/*
11-2. 최대점수 구하기(DFS)
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

struct Question
{
	int score;
	int time;
	Question(int a, int b) {
		score = a;
		time = b;
	}
};
int DFS(int, int);
vector<Question> questionV;
int save[101][1001];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int s, t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		questionV.push_back(Question(s, t));
	}
	cout << DFS(0, 0);
	return 0;
}
int DFS(int L, int time) {
	if (save[L][time] > 0) return save[L][time];
	if (L == n) {
		return 0;
	}
	else {
		int left = 0;
		if (time + questionV[L].time <= m) {
			left = questionV[L].score + DFS(L + 1, time + questionV[L].time);
		}
		int right = DFS(L + 1, time);
		return save[L][time] = max(left, right);
	}
}

/*
모범 답안 반영 전
	(주의1)
	좌로가는 조건을 DFS 맨 앞에 검사해서
	조건에 제한되면 우로가는 경우를 확인 못하고 return하게 잘못 구현함!
	->DFS는 기본 if-else구조 + 제한조건은 else{...}에다가 구현!

	(주의2)
	메모이제이션을 위해서는 밑에서부터 위로 올라오는 경우가 같아야함!
	아래의 코드는 위에서부터 누적해서 인자를 넘기므로
	메모이제이션을 쓸 수 없는 상황인데 메모이제이션을 써서 잘못 됨!
	->메모이제이션을 쓰기 위해서는 누적하지 않고 밑에서부터 더하면서 올라가게 구현!

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Question
{
	int score;
	int time;
	Question(int a, int b) {
		score = a;
		time = b;
	}
};
int DFS(int, int, int);
vector<Question> questionV;
int save[101][1001];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int s, t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		questionV.push_back(Question(s, t));
	}
	cout << DFS(0, 0, 0);
	return 0;
}
int DFS(int L, int time, int score) {
	if (L == n) {
		return  score;
	}
	else {
		int left = 0;
		if (time + questionV[L].time <= m) {
			left = DFS(L + 1, time + questionV[L].time, score + questionV[L].score);
		}
		int right = DFS(L + 1, time, score);
		return save[L][weight] = max(left, right);
	}
}
*/