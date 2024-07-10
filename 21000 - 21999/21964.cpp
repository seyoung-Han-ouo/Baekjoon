#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;

    cin >> N >> S;

    for (int i = N - 5; i < N; i++) cout << S[i];
    cout << '\n';

    return 0;
}