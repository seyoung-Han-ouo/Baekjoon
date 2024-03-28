#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> M >> N;

    int mn = 10000, sum = 0;
    for (int i = 1; ; i++) {
        int n = i * i;

        if (n > N) break;

        if (n >= M && n <= N) {
            sum += n;
            mn = min(mn, n);
        }
    }

    if (sum == 0) 
        cout << "-1\n";
    else 
        cout << sum << '\n' << mn << '\n';

    return 0;
}