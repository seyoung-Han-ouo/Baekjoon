#include <iostream>
#include <algorithm>
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
	sort(arr, arr + N);

	// ���
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';

	delete[] arr;

	return 0;
}