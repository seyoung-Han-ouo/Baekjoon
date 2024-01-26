#include <iostream>
using namespace std;

int arr[250000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, X;
    cin >> N >> X;

    int result = 0, cnt = 0, sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        sum += arr[i];

        if (i >= X) sum -= arr[i - X];

        if (sum == result) cnt++;
        else if (sum > result) {
            result = sum;
            cnt = 1;
        }
    }

    if (result == 0) cout << "SAD\n";
    else cout << result << '\n' << cnt << '\n';

    return 0;
}