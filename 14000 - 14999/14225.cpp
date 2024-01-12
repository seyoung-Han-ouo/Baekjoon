#include <iostream>
using namespace std;

int N, S[20];
bool arr[2000000];

void findSum(int now, int sum);

void findSum(int now, int sum) {
    arr[sum] = true;

    for (int i = now; i < N; i++)
        findSum(i + 1, sum + S[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> S[i];

    findSum(0, 0);

    for (int i = 1; i < 2000000; i++) {
        if (arr[i] == false) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}