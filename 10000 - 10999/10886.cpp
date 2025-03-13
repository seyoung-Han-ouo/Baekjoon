#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		cnt += n;
	}

	if (cnt > N - cnt) 
		cout << "Junhee is cute!\n";
	else 
		cout << "Junhee is not cute!\n";

	return 0;
}