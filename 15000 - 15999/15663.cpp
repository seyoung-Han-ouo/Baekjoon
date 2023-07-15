#include <iostream>
#include <algorithm>
using namespace std;

struct element {
	int n; // �ڿ���
	int cnt; // �ߺ� ��
	int check; // ��� Ƚ��
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

		// ���� �Է��� ���� �ִ� ������ üũ
		for (int j = 0; j < i; j++) {
			if (arr[j].n == n) {
				arr[j].cnt++;
				n = -1;
			}
		}

		// �ߺ��� �Է��� �ƴ� ���
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