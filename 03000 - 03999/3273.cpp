#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
int arr[1000000];

int findCnt();

int findCnt() {
	int l = 0;
	int r = n - 1;

	int cnt = 0;

	while (l < r) {
		int sum = arr[l] + arr[r];

		if (sum == x) cnt++;

		if (sum <= x) l++;
		else r--;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> x;

	sort(arr, arr + n);

	cout << findCnt() << '\n';

	return 0;
}