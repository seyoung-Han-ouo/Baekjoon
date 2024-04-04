#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int M, N, K;
int arr[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int a, int b);

int bfs(int a, int b) {
    queue <pair<int, int>> q;
    q.push({ a, b });
    arr[a][b] = 1;

    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[ny][nx] == 0) {
                q.push({ ny, nx });
                arr[ny][nx] = 1;
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> K;

    while (K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) arr[i][j] = 1;
        }
    }

    vector<int> result;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0) result.push_back(bfs(i, j));
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int n : result) cout << n << ' ';

    return 0;
}