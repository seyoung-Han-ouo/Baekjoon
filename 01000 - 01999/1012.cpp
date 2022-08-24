#include <iostream>
#include <cstring>
using namespace std;

int M, N, K; // ���α��� M, ���α��� N, ���߰� �ɾ��� �ִ� ��ġ�� ���� K

bool field[51][51] = { false }; // ���߹�
bool visited[51][51] = { false }; // �湮����

int x_[4] = { 0, 0, -1, 1 }; // �����¿�
int y_[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_[i];
		int yy = y + y_[i];

		if (xx >= 0 && yy >= 0 && xx < M && yy < N) {
			if (field[xx][yy] && !visited[xx][yy])
				dfs(xx, yy); // ���
		}
	}
}

int main() {
	int T; // �׽�Ʈ ���̽��� ���� 
	cin >> T;

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &M, &N, &K);

		// ���� ��ġ �Է�
		for (int j = 0; j < K; j++) {
			int x, y;
			scanf("%d %d", &x, &y);

			field[x][y] = true;
		}

		int count = 0; // ������ ��

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (field[j][k] && !visited[j][k]) {
					count++;
					dfs(j, k);
				}
			}
		}

		// ���
		printf("%d\n", count);

		// �ʱ�ȭ
		memset(field, false, sizeof(field));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}