#include <iostream>
using namespace std;

// ���� ������ ��Ģ�� �°� ����Ѵ�.
void printStar(int idx, int N) {
	for (int i = 0; i < idx; i++)
		printf(" ");

	for (int i = 0; i < N - (idx * 2); i++)
		printf("*");

	printf("\n");
}

int main() {
	int N;
	cin >> N;

	// �ﰢ��
	for (int i = 0; i < N; i++)
		printStar(i, N * 2 - 1);

	// ���ﰢ��
	for (int i = N - 2; i >= 0; i--) 
		printStar(i, N * 2 - 1);

	return 0;
}