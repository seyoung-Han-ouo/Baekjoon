#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define MAX 318138

bool arr[MAX];
vector<int> super;

void init();

void init() {
	// 소수 찾기
	arr[1] = true;
	for (int i = 2; i < sqrt(MAX); i++) {
		if (arr[i]) continue;

		for (int j = i * i; j < MAX; j += i) arr[j] = true;
	}

	// 슈퍼 소수 찾기
	int cnt = 0;
	for (int i = 2; i < MAX; i++) {
		if (!arr[i]) {
			cnt++;

			if (!arr[cnt]) super.push_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		cout << super[n - 1] << '\n';
	}

	return 0;
}