#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int result[9];

void dfs(int dth, int now);

void dfs(int dth, int now) {
	// ���� ���
	if (dth == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[result[i]]);
		printf("\n");

		return;
	}

	// ���� Ž���ϱ�
	for (int i = now; i < N; i++) {
		result[dth] = i;
		dfs(dth + 1, i);
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	sort(arr, arr + N);

	dfs(0, 0);

	return 0;
}