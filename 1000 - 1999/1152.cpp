#include <iostream>
#include <string>

using namespace std;

int main() {
	// ���� �����ؼ� �Է¹ޱ�
	string S;
	getline(cin, S);
	
	// ���� ���� ã��
	int count = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == ' ') {
			if(i != 0 && i != S.length() - 1)
				count++;
		}
	}

	// ���鸸 �ִ� ���
	if (count == 0 && S.length() == 1 && S[0] == ' ')
		cout << 0;
	// �ܾ��� ���� �� �հ� �� ���� ������ ������ ������ �� + 1�� ����.
	else 
		cout << count + 1;

	return 0;
}