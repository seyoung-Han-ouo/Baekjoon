#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[20001], B[20001];

int binary(int num);

int binary(int num) {
    int low = 0;
    int high = M - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (B[mid] < num) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < M; i++) cin >> B[i];

        sort(B, B + M);

        int sum = 0;
        for (int i = 0; i < N; i++) sum += binary(A[i]);

        cout << sum << '\n';
    }

    return 0;
}