#include <iostream>
#include <algorithm>
using namespace std;

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int arr[100];

string chgString(int n);
bool compare(int a, int b);

// ���ڸ� ���ڿ���
string chgString(int n) {
	string s;

	if (n < 10)
		s = num[n];
	else
		s = num[n / 10] + " " + num[n % 10];

	return s;
}

// ����
bool compare(int a, int b) {
	string s1 = chgString(a);
	string s2 = chgString(b);

	return s1 < s2;
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	int idx = N - M + 1;

	for (int i = 0; i < idx; i++)
		arr[i] = M + i;

	sort(arr, arr + idx, compare);

	// �� �ٿ� 10���� ���
	for (int i = 0; i < idx; i++) {
		printf("%d ", arr[i]);

		if ((i + 1) % 10 == 0) printf("\n");
	}

	return 0;
}