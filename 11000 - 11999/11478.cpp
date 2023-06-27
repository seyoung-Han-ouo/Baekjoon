#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set <string> set;
	string s;
	cin >> s;

	int cnt = 0;

	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j <= s.length() - i; j++)
			set.insert(s.substr(j, i));

		cnt += set.size();
		set.clear();
	}

	printf("%d\n", cnt);

	return 0;
}