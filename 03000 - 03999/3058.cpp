#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;

    while (T--) {
        int sum = 0;
        int mn = 101;

        for (int i = 0; i < 7; i++) {
            int n;
            cin >> n;

            if (n % 2 == 0) {
                sum += n;
                mn = min(mn, n);
            }
        }

        cout << sum << ' ' << mn << '\n';
    }
    
    return 0;
}