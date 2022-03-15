#include <iostream>
#include <algorithm>
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
	sort(arr, arr + N);

	// 출력
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';

	delete[] arr;

	return 0;
}