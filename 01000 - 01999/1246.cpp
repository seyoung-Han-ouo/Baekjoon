#include <iostream>
#include <algorithm>
using namespace std;

int N, M; // N���� �ް�, �� M��
int P[1001];

int find() {
	int big = 0; // �ִ� ����
	int bigIdx = 0; // �ִ� ������ ���� ����

	for (int i = 0; i < M; i++) {
		int num = P[i] * N; // å�� ����

		// ���� ���� �ް��� ������ ���� ��
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