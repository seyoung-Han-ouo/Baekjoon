#include <iostream>
using namespace std;

int main() {
	string s[5];
	int len = 0; // ���� �� ���ڿ��� ����

	for (int i = 0; i < 5; i++) {
		cin >> s[i];

		len = len > s[i].length() ? len : s[i].length();
	}

	// ���η� ���� ������� ���ڵ��� ���
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < s[j].length()) printf("%c", s[j][i]);
		}
	}

	return 0;
}