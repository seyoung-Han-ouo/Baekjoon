#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[15001];

bool binary(int low, int find);

bool binary(int low, int find) {
    int high = N - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == find) return true;

        if (arr[mid] < find) low = mid + 1;
        else high = mid - 1;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (binary(i + 1, M - arr[i])) cnt++;

    cout << cnt << '\n';

    return 0;
}