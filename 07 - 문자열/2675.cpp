#include <iostream>
using namespace std;

int main() {
	// ���̽��� ���� T
	int T;
	cin >> T;

	int R; // �ݺ� Ƚ�� R
	string S; // ���ڿ� S

	for (int i = 0; i < T; i++) {
		cin >> R >> S;

		// ���ڿ��� �� ���ĺ��� R�� �ݺ� ����Ѵ�.
		for (int j = 0; j < S.length(); j++) {
			for (int k = 0; k < R; k++)
				cout << S[j];
		}

		cout << "\n";
	}

	return 0;
}