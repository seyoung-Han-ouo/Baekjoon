#include <iostream>
#include <string>
using namespace std;

int main() {
	string d;
	cin >> d;

	int time[3];

	// �Է��� ���ڿ����� ���� �̾Ƴ���
	time[0] = stoi(d.substr(0, 2));
	time[1] = stoi(d.substr(3, 5));
	time[2] = stoi(d.substr(6));

	int canT = 0; // �� �ڸ��� �� �� �ִ� ������ ����

	for (int i = 0; i < 3; i++) {
		if (time[i] > 59) { // �ʳ� �п��� ���� ���ϴ� ���ڰ� ���� ��
			canT = 0;
			break;
		}

		if (time[i] > 0 && time[i] <= 12) canT++;
	}

	// ���
	cout << canT * 2 << endl;

	return 0;
}