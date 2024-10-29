#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string N;
	cin >> N;

	int len = N.length(), sum = 0;

	for (int i = 0; i < len; i++) {
		int num = N[i] - '0';

		sum += num;
		arr[i] = num;
	}

	sort(arr, arr + len);

	if (arr[0] != 0 || sum % 3 != 0) cout << "-1\n";
	else {
		for (int i = len - 1; i >= 0; i--) cout << arr[i];
	}

	return 0;
}