#include <iostream>
using namespace std;

int main() {
	int N, M, count = 0;
	cin >> N;

	// N��ŭ ���ڸ� �Է¹޴´�.
	for (int i = 0; i < N; i++) {
		cin >> M;

		// 1�� �Ҽ��� �ƴϴ�.
		if (M != 1) {
			for (int i = 2; i <= M; i++) {
				if (i == M) count++;
				if (M % i == 0) break; // �Ҽ��� �ڱ��ڽŰ� 1�����θ� ������ ���������Ѵ�.
			}
		}
	}

	cout << count;

	return 0;
}