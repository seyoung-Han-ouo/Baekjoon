#include <iostream>
using namespace std;

int N, M, K, x, y;
int map[21][21];
int dice[6];

bool canMove(int n);
void move(int n);
int play(int n);

bool canMove(int n) {
	if (n == 1) return (y + 1) < M;
	else if (n == 2) return (y - 1) >= 0;
	else if (n == 3) return (x - 1) >= 0;
	else if (n == 4) return (x + 1) < N;
}

void move(int n) {
	int temp = dice[0];

	if (n == 1) { 
		y++;
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
	else if (n == 2) {
		y--;
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
	}
	else if (n == 3) { 
		x--;
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
		
	}
	else if (n == 4) {
		x++;
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
}

int play(int n) {
	move(n);

	if (map[x][y] == 0) 
		map[x][y] = dice[5];
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}

	return dice[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> map[i][j];
	}

	while (K--) {
		int n;
		cin >> n;

		if (!canMove(n)) continue;

		cout << play(n) << '\n';
	}

	return 0;
}