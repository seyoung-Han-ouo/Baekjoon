#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  
    int N;
    cin >> N;

    for (int i = 1; ; i++) {
        if (i + i * i + 1 == N) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}