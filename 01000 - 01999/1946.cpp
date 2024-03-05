#include <iostream>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;

			arr[a] = b;
		}

		int cnt = 1;
		int mx = arr[1];

		for (int i = 2; i <= N; i++) {
			if (arr[i] < mx) {
				mx = arr[i];
				cnt++;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}