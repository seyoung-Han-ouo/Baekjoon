#include <iostream>
#include <queue>
using namespace std;

int N, dct, cnt = 1;
int arr[101][101];
queue<pair<int, int>> snake;
queue<pair<int, char>> command;

pair<int, int> nextMove();
bool check(int a, int b);
void move(int a, int b);
void turn(char c);

// 다음에 움직이는 위치
pair<int, int> nextMove() {
	int a = snake.back().first;
	int b = snake.back().second;

	if (dct == 0) b++;
	else if (dct == 1) a++;
	else if (dct == 2) b--;
	else a--;

	return { a, b };
}

// 방문할 수 있는 위치인가?
bool check(int a, int b) {
	return (a > 0 && a <= N) && (b > 0 && b <= N) && arr[a][b] != 1;
}

// 뱀 움직이기
void move(int a, int b) {
	// 움직일 수 없는 위치로 가려는 경우
	if (!check(a, b)) {
		cout << cnt << '\n';
		exit(0);
	}

	// 사과를 먹지 않고 이동하는 경우
	if (arr[a][b] == 0) {
		arr[snake.front().first][snake.front().second] = 0;
		snake.pop();
	}
	
	snake.push({ a, b });
	arr[a][b] = 1;
}

// 방향 바꾸기
void turn(char c) {
	if (c == 'L') {
		if (dct == 0) dct = 3;
		else dct--;
	}
	else {
		if (dct == 3) dct = 0;
		else dct++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int K, L;
	snake.push({ 1, 1 });

	cin >> N >> K;
	while (K--) {
		int a, b;
		cin >> a >> b;

		arr[a][b] = 2;
	}

	cin >> L;
	while (L--) {
		int x;
		char c;
		cin >> x >> c;

		command.push({ x, c });
	}

	// 도스 게임 시작
	while (true) {
		pair<int, int> nm = nextMove();
		move(nm.first, nm.second);

		// 방향을 바꿔야 하는 초가 된 경우
		if (!command.empty() && cnt == command.front().first) {
			turn(command.front().second);
			command.pop();
		}

		cnt++;
	}

	return 0;
}