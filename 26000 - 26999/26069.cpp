#include <iostream>
#include <set>
using namespace std;

set <string> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	st.insert("ChongChong");

	for (int i = 0; i < N; i++) {
		string s1, s2;
		cin >> s1 >> s2;

		if (st.find(s1) != st.end() || st.find(s2) != st.end()) {
			st.insert(s1);
			st.insert(s2);
		}
	}

	printf("%d\n", st.size());

	return 0;
}