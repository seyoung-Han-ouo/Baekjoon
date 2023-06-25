#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map <string, int> m;

int findCnt(int M);

// M개의 문자열 중에 총 몇 개가 집합 S에 포함되어 있는가?
int findCnt(int M) {
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		if (m.find(s) != m.end()) cnt++;
	}

	return cnt;
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

		m.insert({ s, i });
	}

	cout << findCnt(M) << "\n";

	return 0;
}