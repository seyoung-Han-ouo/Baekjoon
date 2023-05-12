#include <iostream>
#include <algorithm>
using namespace std;

int N, M; // N개의 달걀, 고객 M명
int P[1001];

int find() {
	int big = 0; // 최대 수익
	int bigIdx = 0; // 최대 수익을 내는 가격

	for (int i = 0; i < M; i++) {
		int num = P[i] * N; // 책정 가격

		// 고객의 수가 달걀의 수보다 작을 때
		if (M - i < N) 
			num = P[i] * (M - i);

		if (big < num) {
			big = num;
			bigIdx = i;
		}
	}

	printf("%d ", P[bigIdx]);

	return big;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
		scanf("%d", &P[i]);

	sort(P, P + M);

	printf("%d\n", find());

	return 0;
}