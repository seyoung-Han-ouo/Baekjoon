#include <iostream>
using namespace std;

int main() {
	// �Է�
	string s;
	cin >> s;

	// ����
	for (int i = 0; i < s.length(); i++) {
		for (int j = i + 1; j < s.length(); j++) {
			if (s[i] < s[j]) {
				char c = s[i];
				s[i] = s[j];
				s[j] = c;
			}
		}
		// ���
		printf("%c", s[i]);
	}

	return 0;
}