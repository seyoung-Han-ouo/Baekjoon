#include <iostream>
#include <ctime>
using namespace std;

int main() {
	time_t timer = time(NULL); // ���� �ð�
	struct tm* t = localtime(&timer);

	// ���
	cout << t->tm_year + 1900 << "-";

	cout.width(2); // ���� �� ����
	cout.fill('0'); // �� ���� 0���� ä���

	cout << t->tm_mon + 1 << "-" << t->tm_mday << endl;

	return 0;
}