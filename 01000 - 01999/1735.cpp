#include <iostream>
using namespace std;

struct bunsoo {
	int A; // 분자
	int B; // 분모
};

int GCD(int a, int b);

// 유클리드 호제법으로 최대공약수 구하기
int GCD(int a, int b) {
	while (b != 0) {
		int n = a % b;

		a = b;
		b = n;
	}

	return a;
}

int main() {
	bunsoo n1, n2, result;
	scanf("%d %d %d %d", &n1.A, &n1.B, &n2.A, &n2.B);

	// 두 분수의 합
	result.A = n1.A * n2.B + n2.A * n1.B;
	result.B = n1.B * n2.B;

	int n = GCD(result.A, result.B);

	printf("%d %d\n", result.A / n, result.B / n);

	return 0;
}