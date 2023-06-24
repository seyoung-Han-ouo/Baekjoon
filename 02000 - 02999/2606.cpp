#include <iostream>
using namespace std;

bool arr[101][101]; // ����Ǿ� �ִ� ��ǻ��
int check[101] = { false }; // ��ǻ�� ���� ����
int cnt = 0; // ������ ��ǻ�� ��

void virus(int n, int now);

// ��ǻ�� ������Ű��
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