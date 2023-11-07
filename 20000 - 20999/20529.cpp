#include <iostream>
#include <map>
using namespace std;

map <string, int> m;

int difCnt(string a, string b, string c);
int choose();

int difCnt(string a, string b, string c) {
	int sum = 0;

	for (int i = 0; i < 4; i++)
		sum += (a[i] != b[i]) + (b[i] != c[i]) + (a[i] != c[i]);

	return sum;
}

int choose() {
	int result = 100000;
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second > 3) return 0;

		i->second--;

		for (auto j = i; j != m.end(); j++) {
			if (j->second > 3) return 0;
			if (j->second == 0) continue;

			j->second--;

			for (auto k = j; k != m.end(); k++) {
				if (k->second > 3) return 0;
				if (k->second == 0) continue;

				result = min(result, difCnt(i->first, j->first, k->first));
			}

			j->second++;
		}

		i->second++;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;

			if (m.count(s)) m[s]++;
			else m.insert({ s, 1 });
		}

		cout << choose() << '\n';

		m.clear();
	}

	return 0;
}