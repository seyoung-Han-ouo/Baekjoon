#include <iostream>
#include <deque>
using namespace std;

deque<string> dq;

void setDeque(string s);

// 입력 받은 배열의 숫자를 dq에 push
void setDeque(string s) {
	dq = deque<string>();

	string now = "";

	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == ',') {
			dq.push_back(now);
			now = "";
		}
		else now += s[i];
	}

	if (now != "") dq.push_back(now);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		string p, s;
		cin >> p >> n >> s;

		setDeque(s);

		bool isReverse = false;
		bool isError = false;

		for (char c : p) {
			if (c == 'R') isReverse = !isReverse;
			else {
				if (dq.empty()) {
					isError = true;
					break;
				}

				if (isReverse) dq.pop_back();
				else dq.pop_front();
			}
		}

		// 출력
		if (isError) cout << "error\n";
		else {
			string result = "[";

			while (!dq.empty()) {
				if (isReverse) {
					result += dq.back();
					dq.pop_back();
				}
				else {
					result += dq.front();
					dq.pop_front();
				}

				if (dq.empty()) break;

				result += ',';
			}

			cout << result << "]\n";
		}
	}

	return 0;
}