#include <iostream>
using namespace std;

int main() {
	string s[5];
	int len = 0; // 가장 긴 문자열의 길이

	for (int i = 0; i < 5; i++) {
		cin >> s[i];

		len = len > s[i].length() ? len : s[i].length();
	}

	// 세로로 읽은 순서대로 글자들을 출력
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < s[j].length()) printf("%c", s[j][i]);
		}
	}

	return 0;
}