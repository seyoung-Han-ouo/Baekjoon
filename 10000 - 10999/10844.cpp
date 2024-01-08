#include <iostream>
using namespace std;

#define MOD 1000000000

long long arr[101][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < 10; i++) arr[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) 
                arr[i][j] = arr[i - 1][j + 1] % MOD;
            else if (j == 9) 
                arr[i][j] = arr[i - 1][j - 1] % MOD;
            else 
                arr[i][j] = (arr[i - 1][j + 1] + arr[i - 1][j - 1]) % MOD;
        }
    }
        
    long long result = 0;
    for (int i = 0; i < 10; i++)
        result += arr[N][i];

    cout << result % MOD << '\n';

    return 0;
}