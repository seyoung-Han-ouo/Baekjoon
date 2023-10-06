#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt = 0;
bool arr[1001][1001];
bool check[1001];

void dfs(int now);

void dfs(int now) {
    check[now] = true;

    for (int i = 1; i <= N; i++)
        if (!check[i] && arr[now][i])  dfs(i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        arr[a][b] = arr[b][a] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (!check[i]) {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt << '\n';

    return 0;
}