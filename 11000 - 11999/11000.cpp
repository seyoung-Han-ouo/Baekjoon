#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Class {
	int start;
	int time;
};

int N;
Class arr[200001];
priority_queue<int> q;

bool compare(Class a, Class b);

bool compare(Class a, Class b) {
	if (a.start == b.start) return a.time < b.time;

	return a.start < b.start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> arr[i].start >> arr[i].time;

	sort(arr, arr + N, compare);
		
	for (int i = 0; i < N; i++) {
		q.push(-arr[i].time);

		if (-q.top() <= arr[i].start) q.pop();
	}

	cout << q.size() << '\n';

	return 0;
}