#include <iostream>
using namespace std;

int main() {
	bool student[30] = {};

	for (int i = 0; i < 28; i++) {
		int n;
		cin >> n; // �Է�

		student[n - 1] = true; // ������ �л� üũ
	}

	// ���
	for (int i = 0; i < 30; i++)
		if (!student[i]) printf("%d\n", i + 1);
	
	return 0;
}