#include <iostream>
#define MOD 1000000009
using namespace std;

long long arr[100001][3];

void df();

void df() {
    arr[1][0] = arr[2][1] = 1;
    arr[3][0] = arr[3][1] = arr[3][2] = 1;

    for (int i = 4; i < 100001; i++) {
        arr[i][0] = (arr[i - 1][1] + arr[i - 1][2]) % MOD;
        arr[i][1] = (arr[i - 2][0] + arr[i - 2][2]) % MOD;
        arr[i][2] = (arr[i - 3][1] + arr[i - 3][0]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    df();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        cout << (arr[n][0] + arr[n][1] + arr[n][2]) % MOD << '\n';
    }

    return 0;
}