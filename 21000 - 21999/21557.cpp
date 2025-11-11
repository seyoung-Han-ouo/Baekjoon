#include <iostream>
using namespace std;

int N, arr[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N - 3; i++) {
        if (arr[0] < arr[N - 1]) arr[N - 1]--;
        else arr[0]--;
    }

    cout << max(arr[0], arr[N - 1]) - 1 << '\n';

    return 0;
}