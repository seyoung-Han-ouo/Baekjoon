#include <iostream>
using namespace std;

long long fibo[91] = { 0, 1, }; // �Ǻ���ġ �� ����

// n��° �Ǻ���ġ �� ���ϱ�
long long findFibo(int n) {
	if (n == 0 || n == 1) 
		return fibo[n];

	if (fibo[n] == 0)
		return fibo[n] = findFibo(n - 1) + findFibo(n - 2);
	
	return fibo[n];
}

int main() {
	int n; // ã�ƾ��ϴ� n��° �Ǻ���ġ ��
	cin >> n;

	// ���
	cout << findFibo(n) << endl;

	return 0;
}