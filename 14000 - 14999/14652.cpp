#include <iostream>
using namespace std;

int main() {
	int N, M, K; // ���߼��� ũ�� N�� M, �Ҿ���� ���߼� ��ȣ K
	cin >> N >> M >> K;

	// ���
	printf("%d %d\n", K / M, K % M);

	return 0;
}