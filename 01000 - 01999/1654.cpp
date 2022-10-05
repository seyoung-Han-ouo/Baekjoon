#include <iostream>
using namespace std;

unsigned int K, N; // ������ �ִ� ������ ���� K, �ʿ��� ������ ���� N
unsigned int arr[10000]; // ������ �ִ� �������� ����
unsigned int high, low = 1;

// �̺�Ž��
int binarySearch() {
	unsigned int cm = 0; // �߶� ������ ����

	while (low <= high) {
		unsigned int mid = (low + high) / 2;
		unsigned int num = 0; // �ڸ� ������ ��

		for (int i = 0; i < K; i++)
			num += (arr[i] / mid);

		// �ڸ� ������ ���� N�� ��
		if (num >= N) {
			if (cm < mid) cm = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return cm;
}

int main() {
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		scanf("%d", &arr[i]);

		// ���� �� ������ ���� ã��
		if (arr[i] > high)
			high = arr[i];
	}

	// ���
	cout << binarySearch() << "\n";

	return 0;
}