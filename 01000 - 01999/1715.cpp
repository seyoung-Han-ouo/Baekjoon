#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> card;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		card.push(-num);
	}

	long long sum = 0;

	while (card.size() > 1) {
		int a = card.top();
		card.pop();

		int b = card.top();
		card.pop();

		card.push(a + b);
		sum += (a + b);
	}

	cout << -sum << '\n';

	return 0;
}