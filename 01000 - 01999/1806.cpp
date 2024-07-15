#include <iostream>
using namespace std;

int N, S;
int arr[100000];

int findMin(int left, int right);

int findMin(int left, int right) {
    int mn = 100002;
    int sum = arr[0];

    while (left <= right && right < N) {
        if (sum < S) sum += arr[++right];
        else {
            mn = min(mn, right - left + 1);
            sum -= arr[left++];
        }
    }

    if (mn == 100002) return 0;
    else return mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];

    cout << findMin(0, 0) << '\n';

    return 0;
}