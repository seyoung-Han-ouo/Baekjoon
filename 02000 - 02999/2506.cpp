#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;

    int sum = 0;
    int last = 0;

    while (N--) {
        int n;
        cin >> n;

        if (last > 0 && n == 1) n += last;
        sum += n;

        last = n;
    }

    cout << sum << '\n';

    return 0;
}