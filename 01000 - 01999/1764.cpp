#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; // 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M
	cin >> N >> M;

	map <string, int> noHear; // 듣도 못한 사람 명단
	string* noHearSee = new string[N]; // 듣도 보도 못한 사람 명단
	int idx = 0; // 듣보잡의 수

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		noHear.insert({ s, i });
	}

	// 듣도 보도 못한 사람의 명단을 구하기
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		if (noHear.find(s) != noHear.end())
			noHearSee[idx++] = s;
	}

	sort(noHearSee, noHearSee + idx);

	// 듣보잡의 수와 그 명단을 사전순으로 출력
	cout << idx << endl;
	for (int i = 0; i < idx; i++)
		cout << noHearSee[i] << "\n";

	return 0;
}