#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int L; // 집합 S의 크기 L
	int S[51]; // 집합에 포함된 정수
	int n; // 구간에 포함되어야 하는 정수

	// 입력
	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> S[i];
	cin >> n;

	// 정렬
	sort(S, S + L);

	int idx = -2;

	// n보다 작은 정수 중에서 n과 가장 가까운 수의 위치 찾기
	for (int i = 0; i < L; i++) {
		// n이 집합 S에 속할 때
		if (S[i] == n) {
			idx = -1;
			break;
		}

		if (S[i] < n) idx = i;
	}

	int count = 0; // n을 포함하는 좋은 구간의 개수

	if (idx != -1) {
		int start = 1; // 구간에 포함될 수 있는 가장 작은 수
		int end = S[0] - 1; // 구간에 포함될 수 있는 가장 큰 수

		if (idx >= 0) {
			start = S[idx] + 1;
			end = S[idx + 1] - 1;
		}

		// n을 포함하는 좋은 구간의 개수 찾기
		for (int i = 0; ; i++) {
			if (start + i > n) break;

			count += (end - n + 1);
		}

		count--;
	}

	// 출력
	printf("%d\n", count);
	
	return 0;
}