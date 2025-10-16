#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	double h;
};

Student arr[51];

bool compare(Student a, Student b);
void print(int N, double d);

bool compare(Student a, Student b) {
	return a.h > b.h;
}

void print(int N, double d) {
	for (int i = 0; i < N; i++) {
		if (arr[i].h != d) break;

		cout << arr[i].name << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int N;
		cin >> N;

		if (N == 0) break;

		for (int i = 0; i < N; i++) 
			cin >> arr[i].name >> arr[i].h;

		sort(arr, arr + N, compare);

		print(N, arr[0].h);
	}

	return 0;
}