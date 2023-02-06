#include <iostream>
using namespace std;

int N, K; // 배열 A의 크기 N, 교환 횟수 K

// 선택 정렬
int selection_sort(int A[]) {
	int count = 0; // 교환 횟수

	//A[1..N]을 오름차순 정렬한다.
	for (int i = N - 1; i > 0; i--) {
		int big = 0;

		// A[]중 가장 큰 수 A[]를 찾는다
		for (int j = 0; j <= i; j++)
			if (A[j] > A[big]) big = j;

		// last와 big이 서로 다르면 A[last]와 A[big]을 교환
		if (i != big) {
			int tmp = A[i];
			A[i] = A[big];
			A[big] = tmp;

			count++;
		}
		
		// K 번째 교환되는 두 개의 수
		if (count == K) {
			printf("%d %d\n", A[big], A[i]);

			return 0;
		}
	}

	return -1;
}

int main() {
	cin >> N >> K;

	int* A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int num = selection_sort(A);

	// 출력
	if (num == -1) printf("-1\n");

	delete[] A;

	return 0;
}