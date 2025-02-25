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

// ������ �����̴� ��ġ
pair<int, int> nextMove() {
	int a = snake.back().first;
	int b = snake.back().second;

	if (dct == 0) b++;
	else if (dct == 1) a++;
	else if (dct == 2) b--;
	else a--;

	return { a, b };
}

// �湮�� �� �ִ� ��ġ�ΰ�?
bool check(int a, int b) {
	return (a > 0 && a <= N) && (b > 0 && b <= N) && arr[a][b] != 1;
}

// �� �����̱�
void move(int a, int b) {
	// ������ �� ���� ��ġ�� ������ ���
	if (!check(a, b)) {
		cout << cnt << '\n';
		exit(0);
	}

	// ����� ���� �ʰ� �̵��ϴ� ���
	if (arr[a][b] == 0) {
		arr[snake.front().first][snake.front().second] = 0;
		snake.pop();
	}
	
	snake.push({ a, b });
	arr[a][b] = 1;
}

// ���� �ٲٱ�
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

	// ���� ���� ����
	while (true) {
		pair<int, int> nm = nextMove();
		move(nm.first, nm.second);

		// ������ �ٲ�� �ϴ� �ʰ� �� ���
		if (!command.empty() && cnt == command.front().first) {
			turn(command.front().second);
			command.pop();
		}

		cnt++;
	}

	return 0;
}