#include <iostream>
#include <cmath>
using namespace std;

bool check(int n);
int length(int n);
void findNum(int n);

int result;
bool button[10] = { false };

bool check(int n) {
    if (n == 0) return !button[0];

    for (int i = n; i > 0; i /= 10)
        if (button[i % 10]) return false;

    return true;
}

int length(int n) {
    if (n == 0) return 1;

    int len = 0;
    for (int j = n; j > 0; j /= 10) len++;

    return len;
}

void findNum(int n) {
    for (int i = 0; i < 1000000; i++) {
        if (check(i)) {
            int len = length(i);

            result = min(result, abs(n - i) + len);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;

        button[n] = true;
    }

    result = abs(N - 100);

    if (N != 100) findNum(N);

    cout << result << '\n';

    return 0;
}