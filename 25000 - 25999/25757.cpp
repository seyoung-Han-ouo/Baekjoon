#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, need = 3;
	char game;

	cin >> N >> game;

	if (game == 'Y') need = 1;
	else if (game == 'F') need = 2;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		arr.insert(s);
	}

	cout << arr.size() / need << '\n';

	return 0;
}