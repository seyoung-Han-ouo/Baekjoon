#include <iostream>
using namespace std;

int main() {
	int T; // 테스트 케이스 수
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		// 출력
		cout << s[0] << s[s.length() - 1] << "\n";
	}
	
	return 0;
}