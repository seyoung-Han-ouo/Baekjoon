#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double R; // ������

	cin >> R;

	// 5�ڸ����� �Ҽ��� �ڸ� ǥ��
	cout << fixed;
	cout.precision(6);

	// ��Ŭ���� �����п��� ���� ����
	cout << R * R * acos(-1) << '\n';

	// �ý� �����п��� ���� ����
	cout << R * R * 2;
	
	return 0;
}