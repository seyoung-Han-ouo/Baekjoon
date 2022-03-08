#include <iostream>
#include <string>

using namespace std;

int main() {
	// 공백 포함해서 입력받기
	string S;
	getline(cin, S);
	
	// 공백 개수 찾기
	int count = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == ' ') {
			if(i != 0 && i != S.length() - 1)
				count++;
		}
	}

	// 공백만 있는 경우
	if (count == 0 && S.length() == 1 && S[0] == ' ')
		cout << 0;
	// 단어의 수는 맨 앞과 맨 끝의 공백을 제외한 공백의 수 + 1과 같다.
	else 
		cout << count + 1;

	return 0;
}