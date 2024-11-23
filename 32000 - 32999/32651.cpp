#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    if (N % 2024 == 0 && N <= 100000) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}