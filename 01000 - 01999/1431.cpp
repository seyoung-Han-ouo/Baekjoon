#include <iostream>
#include <algorithm>
using namespace std;

int sum(string s);
bool compare(string a, string b);

// 모든 자리수의 합 구하기
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

		// 사전순으로 앞서는 것
		if (n1 == n2) return a < b;

		// 작은 합을 가지는 것
		return n1 < n2;
	}

	// 길이가 짧은 것
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