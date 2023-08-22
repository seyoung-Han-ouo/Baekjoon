#include <iostream>
using namespace std;

int N, M, K;
int big = -100000000;

int arr[11][11];
bool check[11][11] = { false };

void dfs(int dth, int num, int start);

void dfs(int dth, int num, int start) {
    if (dth == K) {
        big = max(big, num);
        return;
    }

    for (int i = start; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (check[i][j] || check[i - 1][j] || check[i + 1][j] || check[i][j - 1] || check[i][j + 1]) continue;

            check[i][j] = true;
            dfs(dth + 1, num + arr[i][j], i);
            check[i][j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) cin >> arr[i][j];

    dfs(0, 0, 1);

    cout << big << '\n';

    return 0;
}