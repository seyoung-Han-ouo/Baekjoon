#include <iostream>
using namespace std;

int main() {
	// ���� ���� N
	int N;
	cin >> N;

	// �迭 ����
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// �������� ����
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[j] < arr[i]) {
				int a = arr[i];
				arr[i] = arr[j];
				arr[j] = a;
			}
		}
		// ���
		cout << arr[i] << '\n';
	}

	delete[] arr;

	return 0;
}