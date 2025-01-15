#include <iostream>
#include <vector>
using namespace std;

bool check[20001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, cnt = 0;
    string s;

    cin >> N >> K >> s;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'H') continue;

        for (int j = i - K; j < i + K + 1; j++) {
            if (j < 0 || j >= N || j == i) continue;

            if (!check[j] && s[j] == 'H') {
                cnt++;
                check[j] = true;
                break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}