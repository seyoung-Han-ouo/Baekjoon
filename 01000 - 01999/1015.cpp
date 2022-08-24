#include <iostream>
#include <algorithm>
using namespace std;

struct element {
	int num; // ����
	int idx1; // ���� �Է� �� �ε���
	int idx2; // ũ�� �� �ε���
};

// ���� - ��������
bool compare1(element a, element b) {
	return a.num < b.num;
}

// ���� - �ǵ�����
bool compare2(element a, element b) {
	return a.idx1 < b.idx1;
}

element arr[51];

int main() {
	int N; // �迭 A�� ũ�� N
	cin >> N;

	// �Է�
	for (int i = 0; i < N; i++) {
		cin >> arr[i].num;
		arr[i].idx1 = i;
	}

	// �Է��� ���ڸ� ������������ ����
	stable_sort(arr, arr + N, compare1);

	// �� ������ ���� �ε����� �Է�
	for (int i = 0; i < N; i++)
		arr[i].idx2 = i;

	// ������������ ������ �迭�� �ǵ�����
	stable_sort(arr, arr + N, compare2);

	// ���
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i].idx2);
	cout << endl;

	return 0;
}