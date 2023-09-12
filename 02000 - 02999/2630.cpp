#include <iostream>
using namespace std;

int white = 0, blue = 0;
bool arr[128][128];

void dfs(int x, int y, int size) {
    int cnt = 0;

    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            if (arr[i][j]) cnt++;

    if (cnt == 0) white++;
    else if (cnt == size * size) blue++;
    else {
        dfs(x, y, size / 2);
        dfs(x + size / 2, y, size / 2);
        dfs(x, y + size / 2, size / 2);
        dfs(x + size / 2, y + size / 2, size / 2);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    dfs(0, 0, N);

    cout << white << '\n' << blue << '\n';

    return 0;
}