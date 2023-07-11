#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> map;

bool compare(pair<string, int>& a, pair<string, int>& b);

bool compare(pair<string, int>& a, pair<string, int>& b) {
	if (a.second == b.second) {
		// 알파벳 사전 순으로 배치
		if (a.first.length() == b.first.length())
			return a.first < b.first;

		// 단어의 길이가 길수록 앞에 배치
		return a.first.length() > b.first.length();
	}

	// 자주 나오는 단어일수록 앞에 배치
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		// 길이가 M 이상인 단어인 경우
		if (s.length() >= M) map[s]++;
	}

	vector<pair<string, int>> v(map.begin(), map.end());
	sort(v.begin(), v.end(), compare);

	for (auto const& pair : v)
		cout << pair.first << '\n';

	return 0;
}