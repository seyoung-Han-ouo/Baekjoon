#include <iostream>
#include <set>
using namespace std;

set <string> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s1, s2;
		cin >> s1 >> s2;

		if (s2 == "enter") st.insert(s1);
		else st.erase(s1);
	}

	for (set<string>::iterator iter = --st.end(); ; iter--) {
		cout << *iter << "\n";

		if (iter == st.begin()) break;
	}

	return 0;
}