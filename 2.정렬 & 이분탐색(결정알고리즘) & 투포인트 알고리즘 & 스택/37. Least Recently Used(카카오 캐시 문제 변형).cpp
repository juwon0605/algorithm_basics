//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

/*
37. Least Recently Used(카카오 캐시 문제 변형)
캐시메모리는 CPU와 주기억장치(DRAM) 사이의 고속의 임시 메모리로서 CPU가 처리할 작업
을 저장해 놓았다가 필요할 바로 사용해서 처리속도를 높이는 장치이다. 워낙 비싸고 용량이
작아 효율적으로 사용해야 한다. 철수의 컴퓨터는 캐시메모리 사용 규칙이 LRU 알고리즘을 따
른다. LRU 알고리즘은 Least Recently Used 의 약자로 직역하자면 가장 최근에 사용되지 않
은 것 정도의 의미를 가지고 있습니다. 캐시에서 작업을 제거할 때 가장 오랫동안 사용하지
않은 것을 제거하겠다는 알고리즘입니다.
만약 캐시의 사이즈가 5이고 작업이
2 3 1 6 7 순으로 저장되어 있다면,
(맨 앞이 가장 최근에 쓰인 작업이고, 맨 뒤는 가장 오랫동안 쓰이지 않은 작업이다.)
1) Cache Miss : 해야할 작업이 캐시에 없는 상태로 위 상태에서 만약 새로운 작업인 5번 작
업을 CPU가 사용한다면 Cache miss가 되고 모든 작업이 뒤로 밀리고 5번작업은 캐시의 맨
앞에 위치한다.
5 2 3 1 6
(7번 작업은 캐시에서 삭제된다.)
2) Cache Hit : 해야할 작업이 캐시에 있는 상태로 위 상태에서 만약 3번 작업을 CPU가 사용
한다면 Cache Hit가 되고, 63번 앞에 있는 5, 2번 작업은 한 칸 뒤로 밀리고, 3번이 맨 앞으
로 위치하게 된다.
5 2 3 1 6
--->
3 5 2 1 6
캐시의 크기가 주어지고, 캐시가 비어있는 상태에서 N개의 작업을 CPU가 차례로 처리한다면
N개의 작업을 처리한 후 캐시메모리의 상태를 가장 최근 사용된 작업부터 차례대로 출력하는
프로그램을 작성하세요.
▣ 입력설명
첫 번째 줄에 캐시의 크기인 S(3<=S<=10)와 작업의 개수 N(5<=N<=1,000)이 입력된다.
두 번째 줄에 N개의 작업번호가 처리순으로 주어진다. 작업번호는 1 ~100 이다.
▣ 출력설명
마지막 작업 후 캐시메모리의 상태를 가장 최근 사용된 작업부터 차례로 출력합니다.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int s, n, num, find_idx;
	cin >> s >> n;
	vector<int> cache(s);
	for (int i = 0; i < n; i++) {
		cin >> num;
		bool isNum = false;
		for (int j = 0; j < s; j++) {
			if (num == cache[j]) {
				isNum = true;
				find_idx = j;
				break;
			}
		}
		if (isNum) {
			int temp = cache[find_idx];
			for (int j = find_idx; j > 0; j--) {
				cache[j] = cache[j - 1];
			}
			cache[0] = temp;
		}
		else {
			for (int j = s - 1; j > 0; j--) {
				cache[j] = cache[j - 1];
			}
			cache[0] = num;
		}
	}
	for (int i = 0; i < s; i++) {
		cout << cache[i] << " ";
	}
 	return 0;
}
/*
모범 답안
#include <stdio.h>
int C[20];
int main() {
	freopen("input.txt", "rt", stdin);
	int s, n, a, i, j, pos;
	scanf("%d %d", &s, &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		pos=-1;
		for(j=0; j<s; j++) if(C[j]==a) pos=j;
		if(pos==-1){
			for(j=s-1; j>=1; j--) C[j]=C[j-1];
		}
		else{
			for(j=pos; j>=1; j--) C[j]=C[j-1];
		}
		C[j]=a;
	}
	for(i=0; i<s; i++) printf("%d ", C[i]);
	return 0;
}
*/