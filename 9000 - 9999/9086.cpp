#include <iostream>
using namespace std;

int main() {
	int T; // �׽�Ʈ ���̽� ��
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		// ���
		cout << s[0] << s[s.length() - 1] << "\n";
	}
	
	return 0;
}