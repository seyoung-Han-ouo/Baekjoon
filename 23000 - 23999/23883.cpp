#include <iostream>
#include <map>
using namespace std;

int selection_sort(int N, int K);

map <int, int> m;
int A[500001];

// 선택 정렬 
int selection_sort(int N, int K) {
	int count = 0; // 교환 횟수
	int idx = N - 1;

	map <int, int>::reverse_iterator it = m.rbegin();

	for (it = m.rbegin(); it != m.rend(); ++it) {
		int big = it->second; // A[]중 가장 큰 수

		// last와 big이 서로 다르면 교환이 발생한다.
		if (big != idx) {
			int tmp = A[idx];
			A[idx] = it->first;
			A[big] = tmp;

			// 각 숫자의 현재 인덱스 위치
			it->second = idx;
			map<int, int>::iterator find = m.find(tmp);
			find->second = big;

			count++;
		}

		// K 번째 교환
		if (count == K) {
			printf("%d %d\n", A[big], A[idx]); // 출력

			return 0;
		}

		idx--;
	}

	// 출력
	printf("-1\n");

	return 0;
}

int main() {
	int N, K; //  배열 A의 크기 N, 교환 횟수 K
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		m.insert(map<int, int>::value_type(A[i], i));
	}

	selection_sort(N, K);

	return 0;
}