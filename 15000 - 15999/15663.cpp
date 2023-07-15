#include <iostream>
#include <algorithm>
using namespace std;

struct element {
	int n; // 자연수
	int cnt; // 중복 수
	int check; // 사용 횟수
};

int N, M;
element arr[9];
int result[9];

bool compare(element& a, element& b);
void dfs(int dth);

bool compare(element& a, element& b) {
	return a.n < b.n;
}

void dfs(int dth) {
	if (dth == M) {
		for (int i = 0; i < M; i++) cout << result[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i].check != arr[i].cnt) {
			result[dth] = arr[i].n;
			arr[i].check++;

			dfs(dth + 1);

			arr[i].check--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		// 전에 입력한 적이 있는 수인지 체크
		for (int j = 0; j < i; j++) {
			if (arr[j].n == n) {
				arr[j].cnt++;
				n = -1;
			}
		}

		// 중복된 입력이 아닌 경우
		if (n != -1) {
			arr[i].n = n;
			arr[i].cnt = 1;
			arr[i].check = 0;
		}
	}

	sort(arr, arr + N, compare);

	dfs(0);

	return 0;
}