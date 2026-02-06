#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int time = ((double)M / N) * 24 * 60;

    cout << setfill('0');
    cout << std::setw(2) << time / 60 << ':'
         << std::setw(2) << time % 60 << '\n';

    return 0;
}