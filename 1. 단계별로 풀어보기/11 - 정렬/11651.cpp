#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> num(N, vector<int>(2, 0));

    // �Է�
    for (int i = 0; i < N; i++)
        cin >> num[i][1] >> num[i][0];

    // ����
    sort(num.begin(), num.end());

    // ���
    for (int i = 0; i < N; i++)
        printf("%d %d\n", num[i][1], num[i][0]);

	return 0;
}