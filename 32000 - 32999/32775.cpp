#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int S, F;
    cin >> S >> F;

    if (F < S) cout << "flight\n"; 
    else cout << "high speed rail\n";

    return 0;
}