#include <iostream>
#include <set>
using namespace std;

set<string> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		// 새로운 사람 입장
		if (s == "ENTER") {
			cnt += st.size();
			st.clear();
		}
		else
			st.insert(s);
	}

	cout << cnt + st.size() << "\n";

	return 0;
}