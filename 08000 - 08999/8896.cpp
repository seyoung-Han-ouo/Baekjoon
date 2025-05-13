#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<pair<int, string>> robot;

void push(queue<pair<int, string>> q);
void game(int n);
int findWinner();

void push(queue<pair<int, string>> q) {
	while (!q.empty()) {
		robot.push(q.front());
		q.pop();
	}
}

void game(int n) {
	queue<pair<int, string>> S, R, P;

	while (!robot.empty()) {
		int c = robot.front().second[n];

		if (c == 'S') S.push(robot.front());
		else if (c == 'R') R.push(robot.front());
		else P.push(robot.front());

		robot.pop();
	}

	if (!S.empty() && !R.empty() && !P.empty()) {
		push(P);
		push(S);
		push(R);

		return;
	}

	if (S.empty()) push(P);

	if (R.empty()) push(S);

	if (P.empty()) push(R);
}

int findWinner() {
	for (int i = 0; i < K; i++) game(i);

	if (robot.size() == 0 || robot.size() > 1) return 0;

	return robot.front().first + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;

			robot.push({ i, s });
		}
		
		K = robot.front().second.length();

		cout << findWinner() << '\n';

		robot = queue<pair<int, string>>();
	}

	return 0;
}