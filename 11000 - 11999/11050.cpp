#include <iostream>
using namespace std;

int arr[11] = { 1, 1 }; // ���丮���� �����Ѵ�.

// ���丮�� �Լ�
int factorial(int n) {
	if (arr[n] == 0)
		return arr[n] = n * factorial(n - 1);
	else
		return arr[n];
}

int main() {
	int N, K;
	cin >> N >> K;

	// ���
	printf("%d", factorial(N) / (factorial(K) * factorial(N - K)));

	return 0;
}