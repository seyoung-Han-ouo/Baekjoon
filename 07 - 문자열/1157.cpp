#include <iostream>
using namespace std;

int main() {
	string S; // ���ڿ� S
	cin >> S;

	// �迭 �ʱ�ȭ
	int alpha[26];
	for (int i = 0; i < 26; i++)
		alpha[i] = 0;

	int many = 0;
	for (int i = 0; i < S.length(); i++) {
		// �ҹ��ڿ� 32�� ���ؼ� �빮�ڷ� �����.
		if (S[i] >= 'a' && S[i] <= 'z')
			S[i] -= 32;

		alpha[(int)S[i] - 'A']++;

		// ���� ���� ������ ���ĺ��� ã�´�.
		if (alpha[(int)S[i] - 'A'] > alpha[many])
			many = (int)S[i] - 'A';
	}

	// ���� ���� ���� ���ĺ��� ���� �� �����ϴ� �� Ȯ���Ѵ�.
	int same = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == alpha[many] && many != i) {
			same = -1;
			break;
		}
	}

	// ���
	if(same == -1)
		cout << '?';
	else 
		cout << (char)(many + 'A');

	return 0;
}