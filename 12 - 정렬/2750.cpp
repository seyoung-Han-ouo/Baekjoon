#include <iostream>
using namespace std;

int main() {
	// 수의 개수 N
	int N;
	cin >> N;

	// 배열 생성
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// 오름차순 정렬
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[j] < arr[i]) {
				int a = arr[i];
				arr[i] = arr[j];
				arr[j] = a;
			}
		}
		// 출력
		cout << arr[i] << '\n';
	}

	delete[] arr;

	return 0;
}