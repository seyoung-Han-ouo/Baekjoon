#include <iostream>
using namespace std;

int num[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int idx = s[i] - '0';

		if (idx == 9) num[6]++;
		else num[idx]++;
	}

	num[6] = (num[6] % 2 == 1) ? (num[6] / 2 + 1) : (num[6] / 2);
	
	int mx = 0;
	for (int i = 0; i < 9; i++) mx = max(mx, num[i]);

	cout << mx << '\n';

	return 0;
}