#include <iostream>
using namespace std;

int main() {
	int N; // �� N��
	scanf("%d", &N);

	int turn = N / 3 + N % 3;

	// ����̰� �̱�� SK��, â���̰� �̱�� CY�� ���
	if (turn % 2 == 0)
		printf("SK\n");
	else
		printf("CY\n");

	return 0;
}