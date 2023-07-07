#include <iostream>
#include <algorithm>
using namespace std;

int sum(string s);
bool compare(string a, string b);

// ��� �ڸ����� �� ���ϱ�
int sum(string s) {
	int n = 0;

	for (int i = 0; i < s.length(); i++)
		if (!(s[i] >= 'A' && s[i] <= 'Z')) n += s[i] - '0';

	return n;
}

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		int n1 = sum(a);
		int n2 = sum(b);

		// ���������� �ռ��� ��
		if (n1 == n2) return a < b;

		// ���� ���� ������ ��
		return n1 < n2;
	}

	// ���̰� ª�� ��
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string arr[51];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++)
		cout << arr[i] << "\n";

	return 0;
}