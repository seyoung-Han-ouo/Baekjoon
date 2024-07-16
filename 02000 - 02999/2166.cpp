#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<pair<long long, long long>> dot;

long long sum();
long long sub();

long long sum() {
    long long n = 0;
    for (int i = 0; i < N; i++) {
        if (i == N - 1)
            n += (dot[i].first * dot[0].second);
        else
            n += (dot[i].first * dot[i + 1].second);
    }

    return n;
}

long long sub() {
    long long n = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0)
            n += (dot[i].first * dot[N - 1].second);
        else
            n += (dot[i].first * dot[i - 1].second);
    }

    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        dot.push_back({ x, y });
    }

    long long result = abs(sum() - sub());

    cout << fixed;
    cout.precision(1);
    cout << result / 2.0 << '\n';

    return 0;
}