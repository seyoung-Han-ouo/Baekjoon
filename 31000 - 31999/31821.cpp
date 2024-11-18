#include <iostream>
using namespace std;

int N, M, result;
int menu[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> menu[i];
    cin >> M;

    while (M--) {
        int num;
        cin >> num;

        result += menu[num];
    }

    cout << result << '\n';

    return 0;
}