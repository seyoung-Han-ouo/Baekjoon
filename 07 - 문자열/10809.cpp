#include <iostream>
using namespace std;

int main() {
	// 알파벳 소문자로만 이루어진 단어 S
	string S;
	cin >> S;

	// 배열 초기화
	int a[26];
	for (int i = 0; i < 26; i++)
		a[i] = -1;

	// 알파벳 위치를 a[]에 저장
	for (int i = 0; i < S.length(); i++) {
		if(a[(int)S[i] - 'a'] == -1)
			a[(int)S[i] - 'a'] = i;
	}
		

	// 출력
	for (int i = 0; i < 26; i++)
		cout << a[i] << " ";

	return 0;
}