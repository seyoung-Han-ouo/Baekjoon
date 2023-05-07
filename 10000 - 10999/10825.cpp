#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	string name; // �̸�
	int kr; // ���� ����
	int en; // ���� ����
	int mth; // ���� ����
};

bool compare(Student a, Student b);

Student arr[100001]; // �����̳� ���� �л�

bool compare(Student a, Student b) {
	if (a.kr == b.kr) {
		if (a.en == b.en) {
			if (a.mth == b.mth)
				return a.name < b.name;

			return a.mth > b.mth;
		}

		return a.en < b.en;
	}

	return a.kr > b.kr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i].name >> arr[i].kr >> arr[i].en >> arr[i].mth;

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++)
		cout << arr[i].name << "\n";

	return 0;
}