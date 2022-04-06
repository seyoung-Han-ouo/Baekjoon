#include <iostream>
using namespace std;

int main() {
	// 입력
	string s;
	cin >> s;

	// 정렬
	for (int i = 0; i < s.length(); i++) {
		for (int j = i + 1; j < s.length(); j++) {
			if (s[i] < s[j]) {
				char c = s[i];
				s[i] = s[j];
				s[j] = c;
			}
		}
		// 출력
		printf("%c", s[i]);
	}

	return 0;
}