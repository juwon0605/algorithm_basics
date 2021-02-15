//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
75. 최대 수입 스케쥴(priority_queue 응용문제)
현수는 유명한 강연자이다. N개이 기업에서 강연 요청을 해왔다. 각 기업은 D일 안에 와서 강
연을 해 주면 M만큼의 강연료를 주기로 했다.
각 기업이 요청한 D와 M를 바탕으로 가장 많을 돈을 벌 수 있도록 강연 스케쥴을 짜야 한다.
단 강연의 특성상 현수는 하루에 하나의 기업에서만 강연을 할 수 있다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=10,000)이 주어지고, 다음 N개의 줄에 M(1<=M<=10,000)과
D(1<=D<=10,000)가 차례로 주어진다.
▣ 출력설명
첫 번째 줄에 최대로 벌 수 있는 수입을 출력한다.
*/
struct Lecture
{
	int pay;
	int day;
	Lecture(int a, int b) {
		pay = a;
		day = b;
	}
	bool operator<(const Lecture &b) const {
		return day > b.day;
	}
};
int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n, m, d, max = 0, sum = 0;
	vector<Lecture> lecture_vec;
	priority_queue<int> pQ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> d;
		lecture_vec.push_back(Lecture(m, d));
		if (d > max) max = d;
	}
	sort(lecture_vec.begin(), lecture_vec.end());
	int j = 0;
	for (int i = max; i > 0; i--) {
		while (j < n && lecture_vec[j].day >= i) {
			pQ.push(lecture_vec[j].pay);
			j++;
		}
		if (!pQ.empty()) {
			sum += pQ.top();
			pQ.pop();
		}
	}
	cout << sum;
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct Data{
	int money;
	int when;
	Data(int a, int b){
		money=a;
		when=b;
	}
	bool operator<(const Data &b)const{
		return when>b.when;
	}	
};
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, a, b, res=0, max=-2147000000;	
	vector<Data> T;
	priority_queue<int> pQ;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		T.push_back(Data(a, b));
		if(b>max)
			max=b;
	}
	sort(T.begin(), T.end());	
	j=0;
	for(i=max; i>=1; i--){	
		for( ; j<n; j++){
			if(T[j].when<i) break;			
			pQ.push(T[j].money);
		}
		if(!pQ.empty()){
			res+=pQ.top();
			pQ.pop();
		}
	}
	printf("%d\n",res);
	return 0;
}
*/

/*
모범 답안 반영 전
struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first < b.first) return true;
		else if (a.first == b.first) {
			if (a.second < b.second) return true;
			else return false;
		}
		return false;
	}
};
int main() {
	ios::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n, m, d, sum = 0, cnt = 1, max = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> max_heap;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> d;
		max_heap.push(make_pair(m, d));
		if (d > max) max = d;
	}
	int *flag = new int[max + 1];
	for (int i = 1; i <= max; i++) {
		flag[i] = 0;
	}

	while (!max_heap.empty() && cnt <= max) {
		for (int i = max; i > 0; i--) {
			if (max_heap.top().second >= i && flag[i] == 0) {
				sum += max_heap.top().first;
				flag[i] = 1;
				cnt++;
				break;
			}
		}
		max_heap.pop();
	}
	cout << sum;
	return 0;
}
*/