//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
58. 이진트리 깊이우선탐색(DFS)
아래 그림과 같은 이진트리를 전위순회와 후위순회를 연습해보세요.
      1
  2      3
 4 5    6 7
전위순회 출력 : 1 2 4 5 3 6 7
중위순회 출력 : 4 2 5 1 6 3 7
후위순회 출력 : 4 5 2 6 7 3 1
*/
void DFS_preorder(int v);
void DFS_inorder(int v);
void DFS_postorder(int v);
int main() {
	//freopen("input.txt", "rt", stdin);
	DFS_preorder(1);
	cout << endl;
	DFS_inorder(1);
	cout << endl;
	DFS_postorder(1);
	return 0;
}
void DFS_preorder(int v) {
	if (v > 7) return;
	else {
		cout << v << " ";
		DFS_preorder(v * 2);
		DFS_preorder(v * 2 + 1);
	}
}
void DFS_inorder(int v) {
	if (v > 7) return;
	else {
		DFS_inorder(v * 2);
		cout << v << " ";
		DFS_inorder(v * 2 + 1);
	}
}
void DFS_postorder(int v) {
	if (v > 7) return;
	else {
		DFS_postorder(v * 2);
		DFS_postorder(v * 2 + 1);
		cout << v << " ";
	}
}
/*
모범 답안

*/

/*
모범 답안 반영 전

*/