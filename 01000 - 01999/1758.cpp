#include <iostream>
#include <algorithm>
using namespace std;

int N; // ����� ��
int arr[100001]; // �� ����� �ַ��� �ϴ� ��

long int findSum();
bool compare(int a, int b);

long int findSum() {
	long int sum = 0; // ���� �ִ�

	for (int i = 0; i < N; i++) {
		int num = arr[i] - i > 0 ? arr[i] - i : 0;

		sum += num;
	}

	return sum;
}

bool compare(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	sort(arr, arr + N, compare);

	cout << findSum() << endl;

	return 0;
}