#include <iostream>
using namespace std;

int alpha[26] = {0};

int main() {
	string s;
	int big = -1;

	while (cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			int idx = (int)(s[i] - 'a');
			alpha[idx]++;

			// 가장 많이 나온 글자가 나온 횟수
			if (alpha[idx] > big)
				big = alpha[idx];
		}
	}

	// 출력
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == big)
			cout << (char)(i + 'a');
	}

	return 0;
}