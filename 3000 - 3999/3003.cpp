#include <iostream>
using namespace std;

int main() {
	int piece[6] = { 1, 1, 2, 2, 2, 8 }; // ���� �־�� �ϴ� �ǽ��� ��
	int now[6]; // ���� ������ �ִ� �ǽ��� ��

	// �Է�
	for (int i = 0; i < 6; i++)
		cin >> now[i];

	// ���
	for (int i = 0; i < 6; i++)
		cout << piece[i] - now[i] << " ";
	
	return 0;
}