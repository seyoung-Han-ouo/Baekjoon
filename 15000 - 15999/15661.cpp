#include <iostream>
using namespace std;

int N, result = 10000000;
int arr[20][20];
int check[20];

void dfs(int now);

void dfs(int now) {
    if (now == N) {
        int start = 0;
        int link = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (check[i] && check[j]) start += arr[i][j];
                if (!check[i] && !check[j]) link += arr[i][j];
            }
        }

        if (abs(start - link) < result) result = abs(start - link);

        return;
    }

    for (int i = now; i < N; i++) {
        check[i]++;
        dfs(i + 1);
        check[i]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    dfs(0);

    cout << result << '\n';

    return 0;
}