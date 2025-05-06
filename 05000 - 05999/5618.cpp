#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 1; i <= arr[0]; i++) {
        if (arr[0] % i == 0 && arr[1] % i == 0 && arr[2] % i == 0) cout << i << '\n';
    }

    return 0;
}