#include <iostream>
using namespace std;

long long fibo[91] = { 0, 1, }; // 피보나치 수 저장

// n번째 피보나치 수 구하기
long long findFibo(int n) {
	if (n == 0 || n == 1) 
		return fibo[n];

	if (fibo[n] == 0)
		return fibo[n] = findFibo(n - 1) + findFibo(n - 2);
	
	return fibo[n];
}

int main() {
	int n; // 찾아야하는 n번째 피보나치 수
	cin >> n;

	// 출력
	cout << findFibo(n) << endl;

	return 0;
}