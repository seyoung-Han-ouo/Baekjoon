#include <iostream>
using namespace std;

int main() {
	string S; // ���ڿ� S
	cin >> S;

	// �� ���ĺ��� �ش��ϴ� ���ڸ� ���� �� �ɸ��� �ð��� �迭�� ����
	int alpha[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

	// ��ȭ�� �ɱ� ���ؼ� �ɸ��� �ð�
	int time = 0;
	for (int i = 0; i < S.length(); i++)
		time += alpha[(int)S[i] - 'A'];

	// ���
	cout << time;

	return 0;
}