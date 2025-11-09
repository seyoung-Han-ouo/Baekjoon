#include <iostream>
#include <queue>
using namespace std;

int num[3];
int arr[61][61][61];

int da[6] = { -9, -9, -3, -1, -3, -1 };
int db[6] = { -3, -1, -9, -9, -1, -3 };
int dc[6] = { -1, -3, -1, -3, -9, -9 };

int bfs(int sa, int sb, int sc);

int bfs(int sa, int sb, int sc) {
    queue<pair<int, pair<int, int>>> q;
    q.push({ sa, { sb, sc } });
    arr[sa][sb][sc] = 1;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second.first;
        int c = q.front().second.second;
        int cnt = arr[a][b][c];
        q.pop();

        for (int i = 0; i < 6; i++) {
            int na = a + da[i];
            int nb = b + db[i];
            int nc = c + dc[i];

            if (na < 0) na = 0;
            if (nb < 0) nb = 0;
            if (nc < 0) nc = 0;

            if (arr[na][nb][nc] == 0) {
                q.push({ na, {nb, nc} });
                arr[na][nb][nc] = cnt + 1;
            }
        }
    }

    return arr[0][0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> num[i];

    cout << bfs(num[0], num[1], num[2]) - 1 << '\n';

    return 0;
}