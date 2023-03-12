#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; // �赵 ���� ����� �� N, ���� ���� ����� �� M
	cin >> N >> M;

	map <string, int> noHear; // �赵 ���� ��� ���
	string* noHearSee = new string[N]; // �赵 ���� ���� ��� ���
	int idx = 0; // �躸���� ��

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		noHear.insert({ s, i });
	}

	// �赵 ���� ���� ����� ����� ���ϱ�
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		if (noHear.find(s) != noHear.end())
			noHearSee[idx++] = s;
	}

	sort(noHearSee, noHearSee + idx);

	// �躸���� ���� �� ����� ���������� ���
	cout << idx << endl;
	for (int i = 0; i < idx; i++)
		cout << noHearSee[i] << "\n";

	return 0;
}