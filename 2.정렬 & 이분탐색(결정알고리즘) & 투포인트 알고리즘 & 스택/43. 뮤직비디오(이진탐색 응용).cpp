//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

/*
43. 뮤직비디오(이분검색 응용)
지니레코드에서는 불세출의 가수 조영필의 라이브 동영상을 DVD로 만들어 판매하려 한다.
DVD에는 총 N개의 곡이 들어가는데, DVD에 녹화할 때에는 라이브에서의 순서가 그대로 유지
되어야 한다. 순서가 바뀌는 것을 우리의 가수 조영필씨가 매우 싫어한다. 즉, 1번 노래와 5번
노래를 같은 DVD에 녹화하기 위해서는 1번과 5번 사이의 모든 노래도 같은 DVD에 녹화해야
한다.
지니레코드 입장에서는 이 DVD가 팔릴 것인지 확신할 수 없기 때문에 이 사업에 낭비되는
DVD를 가급적 줄이려고 한다. 고민 끝에 지니레코드는 M개의 DVD에 모든 동영상을 녹화하기
로 하였다. 이 때 DVD의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 그리고 M개의 DVD는
모두 같은 크기여야 제조원가가 적게 들기 때문에 꼭 같은 크기로 해야 한다.
▣ 입력설명
첫째 줄에 자연수 N(1≤N≤1,000), M(1≤M≤N)이 주어진다. 다음 줄에는 조영필이 라이브에서
부른 순서대로 부른 곡의 길이가 분 단위로(자연수) 주어진다. 부른 곡의 길이는 10,000분을
넘지 않는다고 가정하자.
▣ 출력설명
첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.
*/
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, start = 0, end, mid, sum = 0, max = 0, cnt, dvd = 0, res;
	cin >> n >> m;
	int *num_arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num_arr[i];
		sum += num_arr[i];
		if (max < num_arr[i]) max = num_arr[i];
	}
	start = max;
	end = sum;
	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 1;
		dvd = 0;
		for (int i = 0; i < n; i++) {
			dvd += num_arr[i];
			if (dvd > mid) {
				cnt++;
				dvd = num_arr[i];
			}
		}
		if (cnt <= m) {
			res = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << res;
	return 0;
}
/*
모범 답안
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1001], n;
int Count(int s){
	int i, cnt=1, sum=0;
	for(i=1; i<=n; i++){
		if(sum+a[i]>s){
			cnt++;
			sum=a[i];
		}
		else sum=sum+a[i];
	}
	return cnt;
}
int main(){
	freopen("input.txt", "rt", stdin);
	int m, i, lt=1, rt=0, mid, res, maxx=-2147000000;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		rt=rt+a[i];
		if(a[i]>maxx) maxx=a[i];
	}
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(mid>=maxx && Count(mid)<=m){
			res=mid;
			rt=mid-1;
		}
		else lt=mid+1;
	}
	printf("%d\n", res);
	return 0;
}
*/

/*
모범 답안 반영 전
int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, min = 1000000, max = 0, idx = 1, direction = 0;
	cin >> n >> m;
	int *num_arr = new int[n+2];
	int *p_arr = new int[m+2];
	int *sum_arr = new int[m+2];
	vector<int> check_arr1(m + 2);
	vector<int> check_arr2(m + 2);
	for (int i = 1; i <= n; i++) {
		cin >> num_arr[i];
	}
	num_arr[0] = 1000000;
	num_arr[n + 1] = 1000000;
	for (int i = 1; i < m; i++) {
		p_arr[i] = (n / m) * i;
	}
	p_arr[0] = 0;
	p_arr[m] = n;
	p_arr[m + 1] = n + 1;
	for (int i = 1; i <= m; i++) {
		int sum = 0;
		for (int j = p_arr[i-1]+1; j <= p_arr[i]; j++) {
			sum += num_arr[j];
		}
		sum_arr[i] = sum;
	}
	sum_arr[0] = 1000000;
	sum_arr[m + 1] = 1000000;
	int check = 1;
	while (p_arr[idx - 1] < p_arr[idx] && p_arr[idx] < p_arr[idx+1]) {
		// 콘솔 확인용
		//for (int i = 1; i <= m; i++) {
		//	cout << sum_arr[i] << " ";
		//}
		//cout << endl;
		
		// 2번째 전 sum_arr와 완전 일치하는지 판단 (홀수)
if (check % 2 == 1) {
	bool judge = true;
	for (int i = 1; i <= m; i++) {
		if (sum_arr[i] != check_arr1[i]) judge = false;
	}
	if (judge) {
		cout << min;
		return 0;
	}
}
// 2번째 전 sum_arr와 완전 일치하는지 판단 (짝수)
else {
	bool judge = true;
	for (int i = 1; i <= m; i++) {
		if (sum_arr[i] != check_arr2[i]) judge = false;
	}
	if (judge) {
		cout << min;
		return 0;
	}
}
// 2번째 전 sum_arr와 완전 일치하는지 판단을 위해 저장 (홀수)
if (check % 2 == 1) {
	for (int i = 1; i <= m; i++) check_arr1[i] = sum_arr[i];
}
// 2번째 전 sum_arr와 완전 일치하는지 판단을 위해 저장 (짝수)
else {
	for (int i = 1; i <= m; i++) check_arr2[i] = sum_arr[i];
}
// 변경된 sum_arr의 max값을 저장
max = 0;
for (int i = 1; i <= m; i++) {
	if (sum_arr[i] > max) {
		max = sum_arr[i];
		idx = i;
	}
}
// 기존의 max중 가장 작은 min 값을 저장 (정답)
if (max < min) min = max;
// max값의 sum_arr의 전후로 더 작은 값의 sum을 가진 방향으로 값 하나 이동
if (sum_arr[idx - 1] > sum_arr[idx + 1]) {
	sum_arr[idx + 1] += num_arr[p_arr[idx]];
	sum_arr[idx] -= num_arr[p_arr[idx]];
	p_arr[idx]--;
	direction = 1;
}
else if (sum_arr[idx - 1] < sum_arr[idx + 1]) {
	sum_arr[idx - 1] += num_arr[p_arr[idx - 1] + 1];
	sum_arr[idx] -= num_arr[p_arr[idx - 1] + 1];
	p_arr[idx - 1]++;
	direction = -1;
}
// sum_arr[idx - 1] == sum_arr[idx + 1]
// 만약 max값의 sum_arr 전후로 값이 동일하다면,
// 무한루프를 피하기 위해 전 이동 방향과 동일하게 값 하나 이동
else {
	if (direction == 1) {
		sum_arr[idx + 1] += num_arr[p_arr[idx]];
		sum_arr[idx] -= num_arr[p_arr[idx]];
		p_arr[idx]--;
		direction = 1;
	}
	else {
		sum_arr[idx - 1] += num_arr[p_arr[idx - 1] + 1];
		sum_arr[idx] -= num_arr[p_arr[idx - 1] + 1];
		p_arr[idx - 1]++;
		direction = -1;
	}
}
check++;
	}
	cout << min;
	return 0;
}
*/