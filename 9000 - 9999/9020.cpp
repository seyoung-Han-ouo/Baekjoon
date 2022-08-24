#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Goldbach(vector<int> sosu, int n);

void Goldbach(vector<int> sosu, int n) {
	bool isFind = false;
	// n�� �� ������ ��Ÿ�� �� �ִ� �� �Ҽ� ã��
	for (int j = 0; j < sosu.size(); j++) {
		if (isFind) break;

		for (int k = j; k >= 0; k--) {
			if (sosu[j] + sosu[k] == n) {
				// ���
				printf("%d %d\n", sosu[k], sosu[j]);

				isFind = true;
				break;
			}
		}
	}
}

int main() {
	int T, n;
	vector<int> sosu;

	// 2���� 10000������ ���� �߿��� �Ҽ��� ã�´�.
	for (int i = 2; i <= 10000; i++) {
		if (i == 2 || i == 3)
			sosu.push_back(i);

		// ¦���� �Ҽ��� �� �� ����.
		if (i % 2 == 0) continue;

		int num = sqrt(i);
		for (int j = 2; j <= num; j++) {
			// �Ҽ��� �ڱ��ڽŰ� 1�θ� ������ ���������Ѵ�.
			if (i % j == 0) break;
			// �Ҽ��� ã���� �迭�� �߰��Ѵ�.
			if (j == num)
				sosu.push_back(i);
		}
	}

	// �׽�Ʈ ���̽� T �Է�
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> n;

		Goldbach(sosu, n);
	}

	return 0;
}