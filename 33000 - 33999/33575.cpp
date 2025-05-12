#include <iostream>
using namespace std;

#define MAX 100001

int N, M, A, B;
int arr[MAX];
int like[MAX];

int preference();

int preference() {
	int num = 0;	// 연속으로 등장 중인 선호도
	int cnt = 0;	// 연속으로 등장한 횟수
	int result = 0;	// 시간표 선호도

	for (int i = 0; i < N; i++) {
		// 연속 등장이 끝나면
		if (like[arr[i]] != num) {
			// 연속으로 3교시 이상 등장한 경우
			if (cnt >= 3) result += (cnt * num);

			num = 0;
			cnt = 0;
		}

		num = like[arr[i]];
		cnt++;
	}

	// 연속으로 3교시 이상 등장한 경우
	if (cnt >= 3) result += (cnt * num);

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> A >> B;
	for (int i = 0; i < N; i++) cin >> arr[i];

	while (A--) {
		int n;
		cin >> n;

		like[n] = 1;
	}

	while (B--) {
		int n;
		cin >> n;

		like[n] = -1;
	}

	cout << preference() << '\n';

	return 0;
}