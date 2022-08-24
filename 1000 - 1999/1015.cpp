#include <iostream>
#include <algorithm>
using namespace std;

struct element {
	int num; // 원소
	int idx1; // 원소 입력 순 인덱스
	int idx2; // 크기 순 인덱스
};

// 정렬 - 오름차순
bool compare1(element a, element b) {
	return a.num < b.num;
}

// 정렬 - 되돌리기
bool compare2(element a, element b) {
	return a.idx1 < b.idx1;
}

element arr[51];

int main() {
	int N; // 배열 A의 크기 N
	cin >> N;

	// 입력
	for (int i = 0; i < N; i++) {
		cin >> arr[i].num;
		arr[i].idx1 = i;
	}

	// 입력한 숫자를 오름차순으로 정렬
	stable_sort(arr, arr + N, compare1);

	// 각 숫자의 현재 인덱스를 입력
	for (int i = 0; i < N; i++)
		arr[i].idx2 = i;

	// 오름차순으로 정렬한 배열을 되돌리기
	stable_sort(arr, arr + N, compare2);

	// 출력
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i].idx2);
	cout << endl;

	return 0;
}