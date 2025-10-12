#include <iostream>
using namespace std;

string s, frame[5];

void first(int n);
void second(int n);
void third(int n);

void first(int n) {
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) frame[0] += "..*.";
		else frame[0] += "..#.";
	}
	frame[0] += ".";
	frame[4] = frame[0];
}

void second(int n) {
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) frame[1] += ".*.*";
		else frame[1] += ".#.#";
	}
	frame[1] += ".";
	frame[3] = frame[1];
}

void third(int n) {
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0 || ((i - 1) % 3 == 0 && i != 1))
			frame[2] += ("*." + string(1, s[i - 1]));
		else 
			frame[2] += ("#." + string(1, s[i - 1]));

		frame[2] += ".";
	}

	if (n % 3 == 0) frame[2] += "*";
	else frame[2] += "#";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	first(s.length());
	second(s.length());
	third(s.length());

	for (int i = 0; i < 5; i++)
		cout << frame[i] << '\n';

	return 0;
}