#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> map;

bool compare(pair<string, int>& a, pair<string, int>& b);

bool compare(pair<string, int>& a, pair<string, int>& b) {
	if (a.second == b.second) {
		// ���ĺ� ���� ������ ��ġ
		if (a.first.length() == b.first.length())
			return a.first < b.first;

		// �ܾ��� ���̰� ����� �տ� ��ġ
		return a.first.length() > b.first.length();
	}

	// ���� ������ �ܾ��ϼ��� �տ� ��ġ
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

		// ���̰� M �̻��� �ܾ��� ���
		if (s.length() >= M) map[s]++;
	}

	vector<pair<string, int>> v(map.begin(), map.end());
	sort(v.begin(), v.end(), compare);

	for (auto const& pair : v)
		cout << pair.first << '\n';

	return 0;
}