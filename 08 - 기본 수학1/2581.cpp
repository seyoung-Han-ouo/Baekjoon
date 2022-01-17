#include <iostream>
using namespace std;

int main() {
	int N, M;
	
	cin >> M;
	cin >> N;

	int  add = 0, small = N;

	// M부터 N까지의 숫자 중에서 소수를 찾는다.
	for (int i = M; i <= N; i++) {
		for (int j = 2; j <= i; j++) {
			if (j == i) {
				add += i;
				if (i < small) small = i;
			}
			if (i % j == 0) break; // 소수는 자기자신과 1만으로만 나누어 떨어져야한다.
		}
	}

	// 출력
	if (add == 0) cout << -1;
	else {
		cout << add << '\n' << small;
	}

	return 0;
}