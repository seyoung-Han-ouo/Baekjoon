#include <iostream>
using namespace std;

int main() {
	string jaehwan, doctor;

	cin >> jaehwan; // ��ȯ�̰� ���� ��� �� �� �ִ� "aaah"
	cin >> doctor; // �ǻ簡 ��⸦ ���ϴ� "aah"

	// ���
	if (jaehwan.length() >= doctor.length())
		printf("go\n");
	else
		printf("no\n");
	
	return 0;
}