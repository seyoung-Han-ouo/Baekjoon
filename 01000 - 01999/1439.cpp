#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string S;
	cin >> S;

	int cnt = 1;
	char now = S[0];

	for (int i = 1; i < S.length(); i++) {
		if (now != S[i]) {
			now = S[i];
			cnt++;
		}
	}

	cout << cnt / 2 << '\n';

	return 0;
}