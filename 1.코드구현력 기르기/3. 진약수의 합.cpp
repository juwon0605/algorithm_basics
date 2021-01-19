#include<iostream>
using namespace std;

/*
3. 진약수의 합
자연수 N이 주어지면 자연수 N의 진약수의 합을 수식과 함께 출력하는 프로그램을 작성하세
요.
*/

int main() {
	int i, n, sum=1;
	cin >> n;
	cout << "1";
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			sum += i;
			cout << " + " << i;
		}
	}
	cout << " = " << sum;
	return 0;
}

/*
모범 답안
#include<iostream>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, sum=1, i;
	cin>>n;
	cout<<"1";
	for(i=2; i<n; i++){
		if(n%i==0){
			sum+=i;
			cout<<" + "<<i;
		}
	}
	cout<<" = "<< sum;
	return 0;
}
*/