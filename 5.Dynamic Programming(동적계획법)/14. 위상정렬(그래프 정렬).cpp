/*
14. 위상정렬(그래프 정렬)
위상정렬은 어떤 일을 하는 순서를 찾는 알고리즘입니다.
각각의 일의 선후관계가 복잡하게 얽혀있을 때 각각 일의 선후관계를 유지하면서 전체 일의
순서를 짜는 알고리즘입니다.
만약 아래와 같은 일의 순서를 각각 지키면서 전체 일의 순서를 정한다면
1 4 //1번일을 하고 난 후 4번일을 해야한다.
5 4
4 3
2 5
2 3
6 2


전체 일의 순서는 1, 6, 2, 5, 4, 3과 같이 정할 수 있다. 전체 일의 순서는 여러 가지가 있습
니다 그 중에 하나입니다.
▣ 입력설명
첫 번째 줄에 전체 일의 개수 N과 일의 순서 정보의 개수 M이 주어집니다.
두 번째 줄부터 M개의 정보가 주어집니다.
▣ 출력설명
전체 일의 순서를 출력합니다.
▣ 입력예제 1
6 6
1 4
5 4
4 3
2 5
2 3
6 2
▣ 출력예제 1
1 6 2 5 4 3
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	queue<int> Q;
	int n, m, a, b;
	cin >> n;
	vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
	vector<int> preCntV(n + 1, 0);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		matrix[a][b] = 1;
		preCntV[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (preCntV[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		cout << now << " ";
		for (int i = 1; i <= n; i++) {
			if (matrix[now][i] == 1) {
				preCntV[i]--;
				if (preCntV[i] == 0) Q.push(i);
			}
		}
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
	int n, m, a, b, score;
	cin>>n>>m;
	vector<vector<int> > graph(n+1, vector<int>(n+1, 0));
	vector<int> degree(n+1);
	queue<int> Q;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		graph[a][b]=1;
		degree[b]++;
	}
	for(int i=1; i<=n; i++){
		if(degree[i]==0) Q.push(i);
	}
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		cout<<now<<" ";
		for(int i=1; i<=n; i++){
			if(graph[now][i]==1){
				degree[i]--;
				if(degree[i]==0) Q.push(i);
			}
		}
	}
	return 0;
}
*/

/*
모범 답안 반영 전
	linked list를 구현해서 풀려고 했으나, 구현 도중 한계를 발견함.
	예제는 풀 수 있으나, 기존 그래프와 연결되지 않았을 경우 계속 새로운 LinkedList를 생성할 수 있음!

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int data;
	Node* next = NULL;
};
class LinkedList {
public:
	Node* head = new Node();

	int find(int a);
	void insert(int data);
	void midInsert(int pos, int data);
	void reverseInsert(int pos, int data);
	void remove(int a);
	void printData();

	int size = 0;
};
int LinkedList::find(int a) {
	int cnt = 0;
	Node* temp = head;
	while (!(temp->data == a)) {
		temp = temp->next;
		cnt++;
	}
	return cnt;
}
void LinkedList::insert(int data) {
	if (size == 0) {
		head->data = data;
		head->next = NULL;
	}
	else {
		Node* current = new Node();
		current->data = data;
		current->next = NULL;
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = current;
	}
	size++;
}
void LinkedList::midInsert(int pos, int data) {
	//구현 예정
	size++;
}
void LinkedList::reverseInsert(int pos, int data) {
	//구현 예정
	size++;
}
void LinkedList::remove(int a) {
	//구현 예정
	size--;
}
void LinkedList::printData() {
	Node* temp = head;
	for (int i = 0; i < size; i++) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	LinkedList list;
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<int> checkV(n + 1);
	checkV[a]++;
	checkV[b]++;
	list.insert(a);
	list.insert(b);
	for (int i = 1; i < m; i++) {
		cin >> a >> b;
		if (checkV[a] > 0 && checkV[b] > 0) {
			int aIdx = list.find(a);
			int bIdx = list.find(b);
			if (bIdx < aIdx) {
				list.remove(a);
				list.reverseInsert(b, a);
			}
		}
		else if (checkV[a] > 0) {
			list.midInsert(a, b);
		}
		else if (checkV[b] > 0) {
			list.reverseInsert(b, a);
		}
		else {
			//새로운 list를 만들어서 관리해야해서 한계점 발견!
		}
	}
	return 0;
}
*/