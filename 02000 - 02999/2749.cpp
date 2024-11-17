#include <iostream>
#include <unordered_map>
using namespace std;

#define MOD 1000000
#define LL long long

unordered_map<LL, LL> m;

LL fibo(LL n);

LL fibo(LL n) {
    if (m[n]) return m[n];

    LL result;

    if (n % 2 == 0)
        result = (fibo(n / 2) * (fibo(n / 2 + 1) + fibo(n / 2 - 1))) % MOD;
    else
        result = ((fibo((n + 1) / 2) * fibo((n + 1) / 2)) % MOD) + ((fibo((n - 1) / 2) * fibo((n - 1) / 2)) % MOD) % MOD;

    return m[n] = result % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL n;
    cin >> n;

    m[0] = 0;
    m[1] = 1;
    m[2] = 1;

    cout << fibo(n) << '\n';

    return 0;
}