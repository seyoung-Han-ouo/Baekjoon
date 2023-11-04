#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	string S;
	cin >> N >> M >> S;

	char c[2] = { 'I', 'O' };

	int need = 1 + 2 * N;
	int result = 0, cnt = 0;
	bool now = false;

	for (int i = 0; i < M + 1; i++) {
		if (S[i] == c[now]) {
			cnt++;
			now = !now;
		}
		else {
			if (cnt >= need) result += (cnt - need) / 2 + 1;

			if (S[i] == 'I') i--;

			cnt = 0;
			now = false;
		}
	}

	cout << result << '\n';

	return 0;
}