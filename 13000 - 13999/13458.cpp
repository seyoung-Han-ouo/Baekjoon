#include <iostream>
using namespace std;

int arr[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, B, C;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> B >> C;

    long long result = N;

    for (int i = 0; i < N; i++) {
        arr[i] -= B;

        if (arr[i] > 0) result += (arr[i] / C) + (arr[i] % C > 0);
    }

    cout << result << '\n';

    return 0;
}