#include <iostream>
using namespace std;

int best = 0;
int day[16];
int money[16];

void findBest(int N, int now, int sum);

void findBest(int N, int now, int sum) {
    best = best > sum ? best : sum;

    for (int i = now; i <= N; i++) {
        if (i + day[i] - 1 <= N)
            findBest(N, i + day[i], sum + money[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> day[i] >> money[i];

    findBest(N, 1, 0);

    cout << best << '\n';

    return 0;
}