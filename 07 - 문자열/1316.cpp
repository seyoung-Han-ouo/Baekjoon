#include <iostream>
using namespace std;

int main() {
	// �ҹ����� �� 26�� ũ�⸦ ���� �迭
	int alpha[26];
	for (int i = 0; i < 26; i++)
		alpha[i] = 0;

	// �ܾ��� ���� N
	int N;
	cin >> N;

	string S;
	int count = 0;

	for (int i = 0; i < N; i++) {
		cin >> S;
		count++;

		// S[j - 1]�� �����ϱ� ���� ����
		char c = S[0];
		for (int j = 0; j < S.length(); j++) {
			// S[j]�� c�� ���� �ʰ� �迭�� �ش簪�� 0�� �ƴ� ���
			if (c != S[j] && alpha[(int)S[j] - 'a'] != 0) {
				count--;
				break;
			}
			else {
				alpha[(int)S[j] - 'a'] += 1;
				c = S[j];
			}	
		}

		// ���� �ܾ ���� �迭�� �ʱ�ȭ
		for (int j = 0; j < S.length(); j++)
			alpha[(int)S[j] - 'a'] = 0;
	}

	// ���
	cout << count;

	return 0;
}