#include <iostream>
using namespace std;

unsigned int N, M; // ������ �� N, ���������� �ϴ� ������ ���� M
unsigned int tree[1000001]; // ������ ����
unsigned int high = 1, low = 1;

// �̺�Ž��
int binarySearch() {
	unsigned int treeM = 0;

	while (low <= high) {
		unsigned int mid = (low + high) / 2;
		unsigned int sum = 0;

		// ���� mid�� �߶� �������� ���� ���ϱ�
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid)
				sum += (tree[i] - mid);

			// �̹� �ʿ��� ��ŭ �߶��� ��
			if (sum > M) break;
		}

		// sum�� ����� ���� ���� �缳��
		if (sum >= M) {
			low = mid + 1;

			if (treeM < mid)
				treeM = mid;
		}
		else
			high = mid - 1;
	}

	return treeM;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);

		// ���� ū ������ ����
		if (high < tree[i])
			high = tree[i];
	}

	// ���
	cout << binarySearch() << endl;

	return 0;
}