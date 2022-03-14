#include <iostream>
using namespace std;

int main() {
	// 소문자의 수 26의 크기를 가진 배열
	int alpha[26];
	for (int i = 0; i < 26; i++)
		alpha[i] = 0;

	// 단어의 개수 N
	int N;
	cin >> N;

	string S;
	int count = 0;

	for (int i = 0; i < N; i++) {
		cin >> S;
		count++;

		// S[j - 1]을 저장하기 위한 변수
		char c = S[0];
		for (int j = 0; j < S.length(); j++) {
			// S[j]와 c가 같지 않고 배열의 해당값이 0이 아닌 경우
			if (c != S[j] && alpha[(int)S[j] - 'a'] != 0) {
				count--;
				break;
			}
			else {
				alpha[(int)S[j] - 'a'] += 1;
				c = S[j];
			}	
		}

		// 다음 단어를 위해 배열을 초기화
		for (int j = 0; j < S.length(); j++)
			alpha[(int)S[j] - 'a'] = 0;
	}

	// 출력
	cout << count;

	return 0;
}