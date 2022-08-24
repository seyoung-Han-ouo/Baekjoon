#include <iostream>
using namespace std;

int people(int k, int n);

int people(int k, int n) {
	if (k == 0) return n; // 0층의 n호에는 n명이 산다
	if (n == 1) return 1; // 1호에는 무조건 1명만 산다.

	return people(k, n - 1) + people(k - 1, n);
}

int main() {
	// 테스트 데이터 수, k층, n호
	int T, k, n;

	cin >> T;
	for (int i = 0; i < T; i++) {
		// 데이터 값 받기
		cin >> k >> n;

		cout << people(k, n) << '\n';
	}
	
	return 0;
}