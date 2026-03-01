#include <iostream>
using namespace std;

int N, D, M, arr[3];
string S;

int needPower(int n);
int totalPower();

// 최소 사용 에너지량 계산
int needPower(int n) {
    int a = n * D;
    int b = D + ((n > 1) * M);

    return min(a, b);
}

// 총 소비 에너지량 계산
int totalPower() {
    int power = 0;
    int idx = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'H' || S[i] == 'Y' || S[i] == 'U') {
            arr[0] += (S[i] == 'H');
            arr[1] += (S[i] == 'Y');
            arr[2] += (S[i] == 'U');

            power += needPower(i - idx);
            idx = i + 1;
        }
    }

    power += needPower(N - idx);

    return power;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> S >> D >> M;

    int power = totalPower();
    int hyu = min(arr[0], min(arr[1], arr[2]));

    // 출력
    if (power == 0) 
        cout << "Nalmeok\n";
    else 
        cout << power << '\n';

    if (hyu == 0)
        cout << "I love HanYang University\n";
    else
        cout << hyu << '\n';

    return 0;
}