#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int result[9];

void dfs(int dth, int now) {
	if (dth == M) {
		for (int i = 0; i < M; i++) printf("%d ", result[i]);
		printf("\n");

		return;
	}

	for (int i = now + 1; i < N; i++) {
		result[dth] = arr[i];

		dfs(dth + 1, i);
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	dfs(0, -1);

	return 0;
}