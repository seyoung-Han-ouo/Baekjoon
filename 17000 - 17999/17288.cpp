#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int result = 0;
	int cnt = 1;

	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] + 1 == s[i]) cnt++;
		else {
			if (cnt == 3) result++;

			cnt = 1;
		}
	}

	if (cnt == 3) result++;

	cout << result << '\n';

	return 0;
}