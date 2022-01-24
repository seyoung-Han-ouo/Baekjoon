#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, num;
	cin >> N;

	// N�� 10���� ���ų� ũ�� �������� ���Ѵ�.
	if (N < 10) 
		num = N;
	else
		num = sqrt(N);

	// 2���� N Ȥ�� N�� �����ٱ����� ���� �߿��� �Ҽ��� ã�´�.
	for (int i = 2; i <= num; i++) {
		for (int j = 2; j <= i; j++) {
			// �Ҽ��� ã���� ���
			if (j == i) {	
				while (N % i == 0) {
					N /= i;
					printf("%d\n", i);
				}
			}
			else if (i % j == 0) break; // �Ҽ��� �ڱ��ڽŰ� 1�����θ� ������ ���������Ѵ�.
		}
	}

	if(N != 1)
		printf("%d\n", N);

	return 0;
}