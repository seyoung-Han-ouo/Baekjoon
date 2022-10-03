#include <iostream>
using namespace std;

int arr[11] = { 1, 1 }; // 팩토리얼을 저장한다.

// 팩토리얼 함수
int factorial(int n) {
	if (arr[n] == 0)
		return arr[n] = n * factorial(n - 1);
	else
		return arr[n];
}

int main() {
	int N, K;
	cin >> N >> K;

	// 출력
	printf("%d", factorial(N) / (factorial(K) * factorial(N - K)));

	return 0;
}