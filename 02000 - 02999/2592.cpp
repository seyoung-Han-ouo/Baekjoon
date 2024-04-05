#include <iostream>
using namespace std;

int cnt[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int sum = 0;
    int mode = 0;
    int mx = 0;

    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;

        sum += n;
        
        if (++cnt[n / 10] > mx) {
            mode = n;
            mx = cnt[n / 10];
        }
    }

    cout << sum / 10 << '\n' << mode << '\n';

    return 0;
}