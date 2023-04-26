#include <iostream>
#include <set>
using namespace std;

int findMax(int N);

set<int> rope; // ������ ����
int arr[10001] = { 0 }; // �� ������ ����

// �������� �̿��Ͽ� ���ø� �� �ִ� ��ü�� �ִ� �߷��� ���ϱ�
int findMax(int N) {
	int max = 0; // �ִ� �߷�
	int noUse = 0; // ������� �ʴ� ������ ��

	for (set<int>::iterator iter = rope.begin(); iter != rope.end(); iter++) {
		int weight = (N - noUse) * (*iter);

		if (weight > max) max = weight;
		noUse += arr[*iter];
	}

	return max;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		arr[num]++;
		rope.insert(num);
	}

	printf("%d\n", findMax(N));

	return 0;
}