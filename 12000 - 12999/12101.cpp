#include <iostream>
#include <string>
using namespace std;

int n, k, cnt = 0;

void dfs(int sum, string s);

void dfs(int sum, string s) {
    if (sum == n) {
        if (++cnt == k) {
            cout << s << '\n';
            exit(0);
        }

        return;
    }

    for (int i = 1; i < 4; i++) {
        if (sum == 0)
            dfs(sum + i, s + to_string(i));
        else if (sum + i <= n)
            dfs(sum + i, s + "+" + to_string(i));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    dfs(0, "");

    cout << "-1\n";

    return 0;
}