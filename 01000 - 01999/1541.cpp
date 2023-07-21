#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> arr; // 숫자
vector<bool> op; // 기호

int small();

int small() {
	int result = arr[0];
	int idx = 0;

	for (int i = 1; i < arr.size(); i++) {
		if (!op[idx])
			result -= arr[i];
		else {
			result += arr[i];
			idx++;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, a = "";
	cin >> s;

	// 식의 숫자와 기호를 분리
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '-' || s[i] == '+' || i == s.length()) {
			arr.push_back(stoi(a));

			if (s[i] == '-')
				op.push_back(false);
			else
				op.push_back(true);

			a = "";
		}
		else a += s[i];
	}

	cout << small() << '\n';

	return 0;
}