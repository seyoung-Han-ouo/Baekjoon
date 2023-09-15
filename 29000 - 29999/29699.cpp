#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string s = "WelcomeToSMUPC";

    cout << s[(N - 1) % 14] << '\n';

    return 0;
}