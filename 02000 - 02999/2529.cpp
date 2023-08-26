#include <iostream>
#include <string>
using namespace std;

int k;
string mx = "0", mn = "9999999999";
char arr[10];
bool check[10];

bool possible(int a, int b, char c);
void dfs(int cnt, string s);

bool possible(int a, int b, char c) {
    if (c == '<') return a < b;
    if (c == '>') return a > b;
}

void dfs(int cnt, string s) {
    if (cnt == k + 1) {
        if (mn > s) mn = s;
        if (mx < s) mx = s;

        return;
    }

    for (int i = 0; i < 10; i++) {
        if (check[i]) continue;

        if (cnt == 0 || possible(s[cnt - 1] - '0', i, arr[cnt])) {
            check[i] = true;
            dfs(cnt + 1, s + to_string(i));
            check[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    for (int i = 1; i <= k; i++) cin >> arr[i];

    dfs(0, "");

    cout << mx << "\n" << mn << "\n";

    return 0;
}