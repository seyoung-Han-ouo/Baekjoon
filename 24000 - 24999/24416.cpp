#include <iostream>
using namespace std;

int c = 0; // �ڵ�1 ���� Ƚ��

// �Ǻ���ġ �� ���ȣ��
int fib(int n) {
	if (n == 1 || n == 2) { // �ڵ�1
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

	// ���� Ƚ���� ���
	printf("%d %d\n", c, n - 2);

	return 0;
}