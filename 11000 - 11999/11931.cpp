#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

bool compare(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N, compare);

    for (int i = 0; i < N; i++) cout << arr[i] << '\n';

    return 0;
}