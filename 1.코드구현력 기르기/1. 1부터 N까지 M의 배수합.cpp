#include<iostream>
using namespace std;

// aso;ihtwao;ithodihto;aeijto;iaejto;wijasilthaekljrhtaklehtlk
/*
1. 1부터 N까지 M의 배수합
자연수 N이 입력되면 1부터 N까지의 수 중 M의 배수합을 출력하는 프로그램을 작성하세요.
*/

int main() {
	int n, m;
	int sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		if (i%m == 0) {
			sum = sum + i;
		}
	}
	cout << sum;
	return 0;
}

/*
모범 답안
#include<iostream>
int main(){
	int n, m, i, sum=0;
	std::cin>>n>>m;
	for(i=1; i<=n; i++){
		if(i%m==0){
			sum=sum+i;
		}
	}
	std::cout<<sum;
	return 0;
}
*/