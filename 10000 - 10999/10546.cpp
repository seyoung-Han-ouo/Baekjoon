#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> m;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		if (m.find(s) != m.end())
			m[s]++;
		else
			m.insert(make_pair(s, 0));
	}

	for (int i = 0; i < N - 1; i++) {
		string s;
		cin >> s;

		if (m[s] == 0) 
			m.erase(s);
		else
			m[s]--;
	}

	for (auto x : m)
		cout << x.first << endl;

	return 0;
}