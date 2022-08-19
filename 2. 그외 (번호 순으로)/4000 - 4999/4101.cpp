#include <iostream>
using namespace std;

int main() {
	int n, m; // 양의 정수 n, m

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		// 첫 번째 수가 두 번째 수보다 크면 Yes를, 아니면 No를 출력
		if (n > m)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}