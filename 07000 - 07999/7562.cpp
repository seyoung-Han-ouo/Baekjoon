#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int bfs[301][301];
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        queue <pair<int, int>> q;
        int startX, startY;
        int endX, endY;

        cin >> startX >> startY;
        cin >> endX >> endY;

        q.push({ startX, startY });

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            int cnt = bfs[x][y];

            q.pop();

            if (x == endX && y == endY) {
                cout << cnt << '\n';
                break;
            }

            // ����Ʈ �̵�
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // ����Ʈ�� �̵��� �� �ִ� ��ġ�ΰ�?
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && bfs[nx][ny] == 0) {
                    q.push({ nx, ny });
                    bfs[nx][ny] = cnt + 1;
                }
            }
        }

        // �迭 �ʱ�ȭ
        memset(bfs, 0, sizeof(bfs));
    }

    return 0;
}