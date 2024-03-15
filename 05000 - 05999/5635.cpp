#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int yyyy = 0;
	int mm = 0;
	int dd = 0;
};

Student arr[101];

bool compare(Student a, Student b);

bool compare(Student a, Student b) {
	if (a.yyyy == b.yyyy) {
		if (a.mm == b.mm)
			return a.dd < b.dd;
		else
			return a.mm < b.mm;
	}

	return a.yyyy < b.yyyy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].name >> arr[i].dd >> arr[i].mm >> arr[i].yyyy;

	sort(arr, arr + n, compare);

	cout << arr[n - 1].name + "\n" + arr[0].name << '\n';

	return 0;
}