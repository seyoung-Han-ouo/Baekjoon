#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        int n, sum = 1;
        cin >> n;

        if (n == -1) break;

        vector<int> arr;

        for (int i = 2; i < sqrt(n); i++) {
            if (n % i == 0) {
                arr.push_back(i);
                arr.push_back(n / i);

                sum += (i + (n / i));
            }
        }

        // Ãâ·Â
        if (sum != n) cout << n << " is NOT perfect.\n";
        else {
            sort(arr.begin(), arr.end());

            cout << n << " = 1";
            for (int num : arr) cout << " + " << num;
            cout << '\n';
        }
    }

    return 0;
}