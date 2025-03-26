#include <iostream>
#include <queue>
using namespace std;

struct Step {
    int ry = 0, rx = 0;
    int by = 0, bx = 0;
    int cnt = 0;
};

int N, M;
char arr[10][10];
bool visit[10][10][10][10];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool canVisit(int y, int x, int i);
int bfs(int a, int b, int c, int d);

// 방문 가능 여부 확인
bool canVisit(int y, int x, int i) {
    return arr[y + dy[i]][x + dx[i]] != '#' && arr[y][x] != 'O';
}

int bfs(int a, int b, int c, int d) {
    queue<Step> q;

    q.push({ a, b, c, d, 0 });
    visit[a][b][c][d] = true;

    while (!q.empty()) {
        int ry = q.front().ry;
        int rx = q.front().rx;
        int by = q.front().by;
        int bx = q.front().bx;
        int cnt = q.front().cnt;
        q.pop();

        // 10번 이하로 움직여서 빨간 구슬을 구멍으로 뺄 수 없는 경우
        if (cnt >= 10) break;

        for (int i = 0; i < 4; i++) {
            int nry = ry, nrx = rx;
            int nby = by, nbx = bx;
            int d1 = 0, d2 = 0;

            // 빨간 구슬 움직이기
            while (canVisit(nry, nrx, i)) {
                nry += dy[i];
                nrx += dx[i];
                d1++;
            }

            // 파란 구슬 움직이기
            while (canVisit(nby, nbx, i)) {
                nby += dy[i];
                nbx += dx[i];
                d2++;
            }

            // 구슬이 구멍에 들어간 경우
            if (arr[nby][nbx] == 'O') continue;
            if (arr[nry][nrx] == 'O') return cnt + 1;

            // 두 구슬이 같은 칸에 위치한 경우
            if (nrx == nbx && nry == nby) {
                if (d1 > d2) {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else {
                    nbx -= dx[i];
                    nby -= dy[i];
                } 
            }

            // 재방문 방지를 위한 체크
            if (!visit[nry][nrx][nby][nbx]) {
                q.push({ nry, nrx, nby, nbx, cnt + 1 });
                visit[nry][nrx][nby][nbx] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a = 0, b = 0, c = 0, d = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'R') {
                a = i;
                b = j;
            }
            else if (arr[i][j] == 'B') {
                c = i;
                d = j;
            }
        }
    }

    cout << bfs(a, b, c, d) << '\n';
    
    return 0;
}