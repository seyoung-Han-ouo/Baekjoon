#include <iostream>
using namespace std;

int main() {
	// ���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S
	string S;
	cin >> S;

	// �迭 �ʱ�ȭ
	int a[26];
	for (int i = 0; i < 26; i++)
		a[i] = -1;

	// ���ĺ� ��ġ�� a[]�� ����
	for (int i = 0; i < S.length(); i++) {
		if(a[(int)S[i] - 'a'] == -1)
			a[(int)S[i] - 'a'] = i;
	}
		

	// ���
	for (int i = 0; i < 26; i++)
		cout << a[i] << " ";

	return 0;
}