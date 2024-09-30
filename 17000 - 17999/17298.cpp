#include <iostream>
#include <stack>
using namespace std;

int N, nge[1000000];
stack<pair<int, int>> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		while (!st.empty()) {
			if (st.top().second >= a) break;

			nge[st.top().first] = a;
			st.pop();
		}

		st.push({ i, a });
	}

	for (int i = 0; i < N; i++) {
		if (nge[i] == 0) cout << "-1 ";
		else cout << nge[i] << ' ';
	}

	return 0;
}