#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// A :���� �ö󰡴� �Ÿ�, B : �̲������� �Ÿ�, V : ������� ����
	double A, B, V;

	cin >> A >> B >> V;

	cout << (int)ceil((V - A) / (A - B)) + 1;

	return 0;
}