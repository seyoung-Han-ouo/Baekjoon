#include <iostream>
using namespace std;

int N, M;
int arr[100000];

int findCnt(int mid);
int binary();

int findCnt(int mid) {
	int sum = 0, cnt = 1;

	for (int i = 0; i < N; i++) {
		if (mid < arr[i]) {
			cnt = M + 1;
			break;
		}

		if (sum + arr[i] <= mid) sum += arr[i];
		else {
			sum = arr[i];
			cnt++;
		}
	}

	return cnt;
}

int binary() {
	int low = 1;
	int high = 1000000000;
	int result = 0;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (findCnt(mid) > M) low = mid + 1;
		else {
			high = mid - 1;
			result = mid;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	cout << binary() << '\n';

	return 0;
}