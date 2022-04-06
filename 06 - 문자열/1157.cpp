#include <iostream>
using namespace std;

int main() {
	string S; // 문자열 S
	cin >> S;

	// 배열 초기화
	int alpha[26];
	for (int i = 0; i < 26; i++)
		alpha[i] = 0;

	int many = 0;
	for (int i = 0; i < S.length(); i++) {
		// 소문자에 32를 더해서 대문자로 만든다.
		if (S[i] >= 'a' && S[i] <= 'z')
			S[i] -= 32;

		alpha[(int)S[i] - 'A']++;

		// 가장 자주 등장한 알파벳을 찾는다.
		if (alpha[(int)S[i] - 'A'] > alpha[many])
			many = (int)S[i] - 'A';
	}

	// 가장 많이 사용된 알파벳이 여러 개 존재하는 지 확인한다.
	int same = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == alpha[many] && many != i) {
			same = -1;
			break;
		}
	}

	// 출력
	if(same == -1)
		cout << '?';
	else 
		cout << (char)(many + 'A');

	return 0;
}