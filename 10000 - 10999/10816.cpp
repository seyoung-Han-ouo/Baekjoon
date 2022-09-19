#include <iostream>
#include <algorithm>
using namespace std;

int card[500001]; // 가지고 있는 숫자 카드

int main() {
	int N, M;

	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	sort(card, card + N); // 정렬

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);

		// 출력
		printf("%d ", upper_bound(card, card + N, num) - lower_bound(card, card + N, num));
	}

	return 0;
}