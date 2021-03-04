/*
91. STL map 자료구조 활용

Map(Key, Value) : Key 기준(중복없이) Value에 count

ex)input.txt
case01
abcdeaabbcccc

case02
7
book
dog
cat
dog
cat
book
cat
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	string input;
	/*
	case01
	cin >> input;
	map<char, int> M;
	map<char, int>::iterator it;
	for (int i = 0; i < n; i++) {
		M[input[i]]++;
	}
	*/

	/*
	case02
	*/ 
	int n;
	cin >> n;
	map<string, int> M;
	map<string, int>::iterator it;
	for (int i = 0; i < n; i++) {
		cin >> input;
		M[input]++;
	}
	
	// Map 출력
	for (it = M.begin(); it != M.end(); it++) {
		cout << "key: " <<it->first << " value: " << it->second << endl;
	}
	return 0;
}