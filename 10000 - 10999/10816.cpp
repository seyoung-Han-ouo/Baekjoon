#include <iostream>
#include <algorithm>
using namespace std;

int card[500001]; // ������ �ִ� ���� ī��

int main() {
	int N, M;

	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	sort(card, card + N); // ����

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);

		// ���
		printf("%d ", upper_bound(card, card + N, num) - lower_bound(card, card + N, num));
	}

	return 0;
}