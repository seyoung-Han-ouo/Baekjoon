#include <iostream>
#include <queue>
using namespace std;

priority_queue <double, vector<double>, greater<double>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--) {
		int x;
		cin >> x;

		if (x == 0) {
			if (q.empty()) cout << "0\n";
			else {
				int result = q.top();
				if (!(q.top() > result)) result *= -1;

				cout << result << '\n';

				q.pop();
			}
		}
		else {
			if (x < 0) q.push(x * -1);
			else q.push(x + 0.1);
		}
	}

	return 0;
}