#include <iostream>
using namespace std;

string arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int k1 = 0, k2 = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if (arr[i] == "KBS1") k1 = i;
        if (arr[i] == "KBS2") k2 = i;
    }

    for (int i = 0; i < k1; i++) cout << 1;
    for (int i = 0; i < k1; i++) cout << 4;

    if (k1 > k2) k2++;

    for (int i = 0; i < k2; i++) cout << 1;
    for (int i = 1; i < k2; i++) cout << 4;

    return 0;
}