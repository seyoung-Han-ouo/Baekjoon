#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++) cout << ' ';
    cout << "*\n";

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N - i; j++) cout << ' ';
        cout << '*';

        for (int j = 0; j < i * 2 - 1; j++) cout << ' ';
        cout << "*\n";
    }

    return 0;
}