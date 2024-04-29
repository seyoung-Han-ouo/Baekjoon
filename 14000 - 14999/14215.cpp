#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n[3];
    cin >> n[0] >> n[1] >> n[2];

    sort(n, n + 3);

    int sum = n[0] + n[1];

    if (sum <= n[2]) 
        cout << sum * 2 - 1 << '\n';
    else 
        cout << sum + n[2] << '\n';

    return 0;
}