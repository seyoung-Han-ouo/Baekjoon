#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int result[9];
bool check[9];

void dfs(int dth);

void dfs(int dth) {
	// 수열 출력
	if (dth == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", result[i]);
		printf("\n");

		return;
	}

	// 수열 탐색하기
	for (int i = 0; i < N; i++) {
		if (check[i]) continue;

		result[dth] = arr[i];

		check[i] = true;
		dfs(dth + 1);
		check[i] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	sort(arr, arr + N);

	dfs(0);

	return 0;
}