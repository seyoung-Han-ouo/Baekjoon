#include<iostream>
using namespace std;

// 1/1
// 1/2, 2/1
// 3/1, 2/2, 1/3
// 1/4, 2/3, 3/2, 4/1
// Ȧ�� ��°�� ���ڴ� 1�� �����ϰ�, �и�� 1�� �����Ѵ�.
// ¦�� ��°�� �и�� 1�� �����ϰ�, ���ڴ� 1�� �����Ѵ�.
int main() {
	int X, num = 0;
	cin >> X;

	for (int i = 1; ; i++) {
		num += i;
		if (num >= X) {
			// ¦�� ��°
			if (i % 2 == 0)
				cout << i - (num - X) << "/" << 1 + (num - X);
			// Ȧ�� ��°
			else
				cout << 1 + (num - X) << "/" << i - (num - X);
			break;
		}
	}

	return 0;
}