#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

void findCnt(int len, int need);

void findCnt(int len, int need) {
    int cnt = 0;
    int result = 0;

    for (int i = len; i >= 0; i--) {
        cnt += arr[i];
        result++;

        if (cnt >= need) {
            cout << result << '\n';
            return;
        }
    }

    cout << "STRESS\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    findCnt(N - 1, M * K);

    return 0;
}