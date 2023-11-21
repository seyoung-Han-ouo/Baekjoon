#include <iostream>
#include <queue>
#include <map>
using namespace std;

map<int, int> m;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

void init();
void insert(int n);
void popMax();
void popMin();

// 큐, 맵 초기화
void init() {
	m = map<int, int>();
	maxq = priority_queue<int>();
	minq = priority_queue<int, vector<int>, greater<int>>();
}

// 데이터를 삽입
void insert(int n) {
	m[n] += 1;
	maxq.push(n);
	minq.push(n);
}

// 우선순위가 가장 높은 것 삭제
void popMax() {
	while (true) {
		if (m[maxq.top()] == 0) maxq.pop();
		else {
			m[maxq.top()]--;
			maxq.pop();

			break;
		}
	}
}

// 우선순위가 가장 낮은 것 삭제
void popMin() {
	while (true) {
		if (m[minq.top()] == 0) minq.pop();
		else {
			m[minq.top()]--;
			minq.pop();

			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		init();

		int k, cnt = 0;
		cin >> k;

		while (k--) {
			char c;
			int n;

			cin >> c >> n;

			if (c == 'I') {
				insert(n);
				cnt++;
			}
			else {
				if (cnt > 0) {
					if (n == 1) popMax();
					else popMin();

					cnt--;
				}
			}
		}

		// 출력
		if (cnt == 0) cout << "EMPTY\n";
		else {
			while (true) {
				if (m[maxq.top()] > 0) {
					cout << maxq.top() << ' ';
					break;
				}

				maxq.pop();
			}

			while (true) {
				if (m[minq.top()] > 0) {
					cout << minq.top() << '\n';
					break;
				}

				minq.pop();
			}
		}
	}

	return 0;
}