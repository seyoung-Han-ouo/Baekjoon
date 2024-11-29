#include <iostream>
using namespace std;

int N, M;
char map[1001][1001];
int check[1001][1001];

// 방문 가능 여부 확인
bool canVisit(int y, int x) {
    return (y >= 0 && y < N) && (x >= 0 && x < M);
}

// 해당 탐색으로 방문한 칸들이 새로운 집합인가?
bool isNewGroup(int y, int x, int num) {
    if (check[y][x] == num) return true;
    if (check[y][x] != 0 && check[y][x] != num) return false;

    check[y][x] = num;

    // 상하좌우
    if (map[y][x] == 'U' && canVisit(y - 1, x)) return isNewGroup(y - 1, x, num);
    else if (map[y][x] == 'D' && canVisit(y + 1, x)) return isNewGroup(y + 1, x, num);
    else if (map[y][x] == 'L' && canVisit(y, x - 1)) return isNewGroup(y, x - 1, num);
    else if (map[y][x] == 'R' && canVisit(y, x + 1)) return isNewGroup(y, x + 1, num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> map[i][j];
    }

    int cnt = 0;
    int num = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (check[i][j] == 0) {
                if (isNewGroup(i, j, num++)) cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}