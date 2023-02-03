#include <iostream>
#include <algorithm>
using namespace std;

int* arr;

// �̺�Ž��
int binarySearch(int key, int low, int high) {
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (key == arr[mid]) // ������
			return 1;

		// ���� �ٽ� ���ϱ�
		if (key > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return 0; // �������� ����
}

int main() {
	int N; // ����̰� ������ �ִ� ���� ī���� ����
	cin >> N;

	arr = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N); // ����

	int M; // ã�ƾ� �ϴ� ���� ����
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num; // ã�ƾ� �ϴ� ��
		scanf("%d", &num);

		// ���
		printf("%d ", binarySearch(num, 0, N - 1));
	}

	delete[] arr;

	return 0;
}