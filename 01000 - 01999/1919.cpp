#include <iostream>
using namespace std;

int main() {
	string a, b; // 두 영어 단어

	cin >> a >> b;

	int count = 0; // 두 영어 단어에 모두 포함되는 문자의 수

	// 두 영어 단어에 모두 포함되는 문자의 수 구하기
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				b[j] = 'A';
				count++;
				break;
			}
		}
	}

	// 출력
	printf("%d\n", (a.length() - count) + (b.length() - count));

	return 0;
}