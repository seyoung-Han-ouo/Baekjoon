#include <iostream>
using namespace std;

int N;
int big = -1000000000;
int small = 1000000000;
int num[11];
int op[4]; // '+', '-', '*', '/'

void dfs(int dth, int result);

void dfs(int dth, int result) {
	if (dth == N) {
		if (result > big) 
			big = result;

		if (result < small) 
			small = result;

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;

			if (i == 0)
				dfs(dth + 1, result + num[dth]);
			else if (i == 1)
				dfs(dth + 1, result - num[dth]);
			else if (i == 2)
				dfs(dth + 1, result * num[dth]);
			else
				dfs(dth + 1, result / num[dth]);

			op[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> op[i];

	dfs(1, num[0]);

	cout << big << '\n' << small << '\n';

	return 0;
}