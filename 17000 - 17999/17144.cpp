#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C, T;
int arr[50][50];
vector<int> air;
queue<pair<int, pair<int, int>>> newDust;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dustSpread();
void moveUp(int x, int start, int end);
void moveDown(int x, int start, int end);
void moveLeft(int y);
void moveRight(int y);

void dustSpread() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] > 0) {
                int cnt = 0;

                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if (nx >= 0 && nx < C && ny >= 0 && ny < R && arr[ny][nx] != -1) {
                        newDust.push({ arr[i][j] / 5, { ny, nx } });
                        cnt++;
                    }
                }

                arr[i][j] -= (arr[i][j] / 5 * cnt);
            }
        }
    }

    while (!newDust.empty()) {
        int x = newDust.front().second.second;
        int y = newDust.front().second.first;
        int a = newDust.front().first;

        newDust.pop();

        arr[y][x] += a;
    }
}

void moveUp(int x, int start, int end) {
    for (int i = start; i < end; i++)
        arr[i][x] = arr[i + 1][x];
}

void moveDown(int x, int start, int end) {
    for (int i = start; i > end; i--)
        arr[i][x] = arr[i - 1][x];
}

void moveLeft(int y) {
    for (int i = 0; i < C - 1; i++)
        arr[y][i] = arr[y][i + 1];
}

void moveRight(int y) {
    arr[y][0] = 0;
    for (int i = C - 1; i > 0; i--)
        arr[y][i] = arr[y][i - 1];
    arr[y][0] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == -1) air.push_back(i);
        }
    }

    while (T--) {
        dustSpread();

        moveDown(0, air[0], 0);
        moveLeft(0);
        moveUp(C - 1, 0, air[0]);
        moveRight(air[0]);

        moveUp(0, air[1], R - 1);
        moveLeft(R - 1);
        moveDown(C - 1, R - 1, air[1]);
        moveRight(air[1]);
    }

    int sum = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] > 0) sum += arr[i][j];
        }
    }

    cout << sum << '\n';

    return 0;
}