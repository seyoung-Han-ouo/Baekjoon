#include <iostream>
using namespace std;

int N, M;
bool arr[101];

void boy(int n);
void girl(int n);

void boy(int n) {
    for (int i = 1; i * n <= N; i++) arr[i * n] = !arr[i * n];
}

void girl(int n) {
    arr[n] = !arr[n];

    for (int i = 1; i <= N; i++) {
        if (n - i < 1 || n + i > N) break;

        if (arr[n - i] == arr[n + i]) {
            arr[n - i] = !arr[n - i];
            arr[n + i] = !arr[n + i];
        }
        else break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cin >> M;

    while (M--) {
        int g, n;
        cin >> g >> n;

        if (g == 1) boy(n);
        else girl(n);
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i];

        if (i % 20 == 0 && i > 1) cout << '\n';
        else cout << ' ';
    }

    return 0;
}