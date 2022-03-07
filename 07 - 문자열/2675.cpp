#include <iostream>
using namespace std;

int main() {
	// 케이스의 개수 T
	int T;
	cin >> T;

	int R; // 반복 횟수 R
	string S; // 문자열 S

	for (int i = 0; i < T; i++) {
		cin >> R >> S;

		// 문자열의 각 알파벳을 R번 반복 출력한다.
		for (int j = 0; j < S.length(); j++) {
			for (int k = 0; k < R; k++)
				cout << S[j];
		}

		cout << "\n";
	}

	return 0;
}