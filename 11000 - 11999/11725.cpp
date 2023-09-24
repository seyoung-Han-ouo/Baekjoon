#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[100001];
int result[100001];

void dfs(int n) {
    for (int i = 0; i < arr[n].size(); i++) {
        int next = arr[n][i];

        if (result[next] == 0) {
            result[next] = n;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) cout << result[i] << '\n';

    return 0;
}