#include <iostream>
using namespace std;

int N, cnt = 0;
bool check[1001];

void dfs(int dth, int now, int sum);

void dfs(int dth, int now, int sum) {
    if (dth == N) {
        if (!check[sum]) {
            check[sum] = true;
            cnt++;
        }

        return;
    }

    int arr[4] = { 1, 5, 10, 50 };

    for (int i = now; i < 4; i++)
        dfs(dth + 1, i, sum + arr[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    dfs(0, 0, 0);

    cout << cnt << '\n';

    return 0;
}