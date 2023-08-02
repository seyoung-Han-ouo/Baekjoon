#include <iostream>
using namespace std; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int E, S, M;
	cin >> E >> S >> M;

	int e = 0, s = 0, m = 0;

	for (int i = 1; ; i++) {
		e++;
		s++;
		m++;

		if (e > 15) e -= 15;
		if (s > 28) s -= 28;
		if (m > 19) m -= 19;

		if (e == E && s == S && m == M) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}