#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

struct Country {
	int r = 0;
	int c = 0;
};

int N, L, R;
int arr[50][50];
bool check[50][50];

bool isMove = false;	// �α� �̵��� ����
Country alliance[2501];	// ����
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void poepleMove(int cnt, int num);
void bfs(int sr, int sc);

// ������ �α� �̵�
void poepleMove(int cnt, int num) {
	for (int i = 0; i < cnt; i++) arr[alliance[i].r][alliance[i].c] = num;
}

// �ʺ�켱Ž��
void bfs(int sr, int sc) {
	int cnt = 0, idx = 0, sum = 0;

	alliance[cnt++] = { sr, sc };
	check[sr][sc] = true;
	sum = arr[sr][sc];

	while (idx != cnt) {
		Country now = alliance[idx++];

		// �����¿��� ���� Ȯ���ϰ� ���ǿ� �����ϸ� ���漱 ����
		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			int people = abs(arr[nr][nc] - arr[now.r][now.c]);

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || check[nr][nc]) continue;

			if ((people >= L && people <= R)) {
				alliance[cnt++] = { nr, nc };
				check[nr][nc] = true;
				sum += arr[nr][nc];

				isMove = true;
			}
		}
	}

	// �α� �̵�
	poepleMove(cnt, sum / cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}

	int day = 0;

	while (true) {
		isMove = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!check[i][j]) bfs(i, j);
			}
		}

		if (isMove) day++;
		else {
			cout << day << '\n';
			break;
		}

		memset(check, false, sizeof(check));
	}

	return 0;
}