#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> num(N, vector<int>(2, 0));

    // 입력
    for (int i = 0; i < N; i++)
        cin >> num[i][1] >> num[i][0];

    // 정렬
    sort(num.begin(), num.end());

    // 출력
    for (int i = 0; i < N; i++)
        printf("%d %d\n", num[i][1], num[i][0]);

	return 0;
}