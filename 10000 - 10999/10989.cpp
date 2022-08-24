#include <iostream>
using namespace std;

// 배열
int arr[10001] = { 0 };

int main() {
	// 수의 개수 N
	int N;
	scanf("%d", &N);

	// 입력
	for (int i = 0; i < N; i++) {
		int c;
		scanf("%d", &c);

		arr[c]++;
	}

	// 출력
	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++)
				printf("%d\n", i);
		}
	}

	return 0;
}