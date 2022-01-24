#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	// M���� N Ȥ�� N������ ���� �߿��� �Ҽ��� ã�´�.
	for (int i = M; i <= N; i++) {
		if (i == 2 || i == 3) 
			printf("%d\n", i);
		// ¦���� �Ҽ��� �� �� ����.
		if (i % 2 == 0) continue;

		int num = sqrt(i);
		for (int j = 2; j <= num; j++) {
			// �Ҽ��� �ڱ��ڽŰ� 1�����θ� ������ ���������Ѵ�.
			if (i % j == 0) break;
			// �Ҽ��� ã���� ���
			if (j == num)
				printf("%d\n", i);
		}
	}

	return 0;
}