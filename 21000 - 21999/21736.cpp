#include <iostream>
using namespace std;

int N, M, cnt = 0;
char arr[600][600];
bool check[600][600];

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y);

void dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;

    check[x][y] = true;

    if (arr[x][y] == 'X') return;
    if (arr[x][y] == 'P') cnt++;

    for (int i = 0; i < 4; i++)
        if (!check[x + dx[i]][y + dy[i]]) dfs(x + dx[i], y + dy[i]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int sX = -1, sY = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if (sX == -1) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 'I') {
                    sX = i;
                    sY = j;

                    break;
                }
            }
        }
    }

    dfs(sX, sY);

    if (cnt == 0) cout << "TT\n";
    else cout << cnt << '\n';

    return 0;
}