//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
74. 최소힙(priority_queue : 우선순위 큐)
최소힙은 완전이진트리로 구현된 자료구조입니다. 그 구성은 부모 노드값이 왼쪽자식과 오른
쪽 자식노드의 값보다 작게 트리를 구성하는 것입니다. 그렇게 하면 트리의 루트(root)노드는
입력된 값들 중 가장 작은 값이 저장되어 있습니다. 예를 들어 5 3 2 1 4 6 7순으로 입력되
면 최소힙 트리는 아래와 같이 구성됩니다.
   1
  2 3
5 4 6 7
최소힙 자료를 이용하여 다음과 같은 연산을 하는 프로그램을 작성하세요.
1) 자연수가 입력되면 최소힙에 입력한다.
2) 숫자 0 이 입력되면 최소힙에서 최솟값을 꺼내어 출력한다.
 (출력할 자료가 없으면 -1를 출력한다.)
3) -1이 입력되면 프로그램 종료한다.
▣ 입력설명
첫 번째 줄부터 숫자가 입력된다. 입력되는 숫자는 100,000개 이하이며 각 숫자의 크기는 정
수형 범위에 있다.
▣ 출력설명
2) 연산을 한 결과를 보여준다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int num;
	priority_queue<int> min_heap;
	while (1) {
		cin >> num;
		if (num == -1) break;
		if (num == 0) {
			if (min_heap.empty()) cout << -1 << endl;
			else {
				cout << -min_heap.top() << endl;
				min_heap.pop();
			}
		}
		else min_heap.push(-num);
	}
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int a;
	priority_queue<int> pQ;
	while(true){
		scanf("%d",&a);
		if(a==-1) break;
		if(a==0){
			if(pQ.empty()) printf("-1\n");
			else{
				printf("%d\n", -pQ.top());
				pQ.pop();
			}
		}
		else pQ.push(-a);
	}
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	//freopen("input.txt", "rt", stdin);
	int num;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	while (1) {
		cin >> num;
		if (num == -1) break;
		if (num == 0) {
			if (min_heap.empty()) cout << -1 << endl;
			else {
				cout << min_heap.top() << endl;
				min_heap.pop();
			}
		}
		else min_heap.push(num);
	}
	return 0;
}
*/