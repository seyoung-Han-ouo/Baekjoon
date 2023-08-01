#include <iostream>
#include <algorithm>
using namespace std; 

int N;
char candy[50][50];

int checkGaro(int n);
int checkSero(int n);

// 행에서 연속적인 사탕 개수 체크
int checkGaro(int n) {
	int result = 0, cnt = 1;
	char c = candy[n][0];

	for (int i = 1; i < N; i++) {
		if (candy[n][i] == c) cnt++;
		else {
			c = candy[n][i];
			result = max(result, cnt);
			cnt = 1;
		}
	}

	return max(result, cnt);
}

// 열에서 연속적인 사탕 개수 체크
int checkSero(int n) {
	int result = 0, cnt = 1;
	char c = candy[0][n];

	for (int i = 1; i < N; i++) {
		if (candy[i][n] == c) cnt++;
		else {
			c = candy[i][n];
			result = max(result, cnt);
			cnt = 1;
		}
	}

	return max(result, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> candy[i][j];

	int result = 0;

	// 행에서 교환
	for (int i = 0; i < N; i++) {
		if (result == N) break;

		for (int j = 0; j < N - 1; j++) {
			swap(candy[i][j], candy[i][j + 1]);
			result = max(result, checkGaro(i));
			result = max(result, max(checkSero(j), checkSero(j + 1)));
			swap(candy[i][j], candy[i][j + 1]);
		}
	}

	// 열에서 교환
	for (int i = 0; i < N; i++) {
		if (result == N) break;

		for (int j = 0; j < N - 1; j++) {
			swap(candy[j][i], candy[j + 1][i]);
			result = max(result, checkSero(i));
			result = max(result, max(checkGaro(j), checkGaro(j + 1)));
			swap(candy[j][i], candy[j + 1][i]);
		}
	}

	cout << result << '\n';
}