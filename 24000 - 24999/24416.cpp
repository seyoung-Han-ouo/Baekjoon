#include <iostream>
using namespace std;

int c = 0; // 코드1 실행 횟수

// 피보나치 수 재귀호출
int fib(int n) {
	if (n == 1 || n == 2) { // 코드1
		c++;
		return 1;
	}
	else 
		return (fib(n - 1) + fib(n - 2));
}

int main() {
	int n;
	cin >> n;

	fib(n);

	// 실행 횟수를 출력
	printf("%d %d\n", c, n - 2);

	return 0;
}