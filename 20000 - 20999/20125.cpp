#include <iostream>
using namespace std;

int N;
char arr[1001][1001];

int findLen(int x, int y, int dx, int dy);

// 사지의 길이 구하기
int findLen(int x, int y, int dx, int dy) {
    int cnt = 0;

    while (true) {
        if (arr[x][y] == '_' || x < 1 || y < 1 || x > N || y > N) break;

        x += dx;
        y += dy;
        cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x = -1, y = -1; // 심장의 위치

    cin >> N; 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];

            // 가장 먼저 입력되는 *(머리)로 심장의 좌표 구하기
            if (arr[i][j] == '*' && x == -1) {
                x = i + 1;
                y = j;
            }
        }
    }

    int body = findLen(x + 1, y, 1, 0); // 허리의 길이

    cout << x << ' ' << y << '\n';
    cout << findLen(x, y - 1, 0, -1) << ' ' << findLen(x, y + 1, 0, 1) << ' ' << body << ' ' 
        << findLen(x + body + 1, y - 1, 1, 0) << ' ' << findLen(x + body + 1, y + 1, 1, 0) << '\n';

    return 0;
}