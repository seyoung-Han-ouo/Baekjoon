#include <iostream>
using namespace std;

bool arr[101][101]; // 연결되어 있는 컴퓨터
int check[101] = { false }; // 컴퓨터 감염 여부
int cnt = 0; // 감염된 컴퓨터 수

void virus(int n, int now);

// 컴퓨터 감염시키기
void virus(int n, int now) {
	if (!check[now]) {
		check[now] = true;
		cnt++;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[now][i] && !check[i]) virus(n, i);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a][b] = true;
		arr[b][a] = true;
	}

	virus(n, 1);

	printf("%d\n", cnt - 1);

	return 0;
}