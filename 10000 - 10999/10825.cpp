#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	string name; // 이름
	int kr; // 국어 점수
	int en; // 영어 점수
	int mth; // 수학 점수
};

bool compare(Student a, Student b);

Student arr[100001]; // 도현이네 반의 학생

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