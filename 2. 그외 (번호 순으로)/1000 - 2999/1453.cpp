#include <iostream>
using namespace std;

bool seat[101] = {};

int main() {
	int N; // �մ��� �� N
	cin >> N;

	int count = 0; // �������ϴ� ����� ��

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		// �������ϴ� ���
		if (seat[num]) count++;
		
		seat[num] = true;
	}

	// ���
	cout << count << endl;

	return 0;
}