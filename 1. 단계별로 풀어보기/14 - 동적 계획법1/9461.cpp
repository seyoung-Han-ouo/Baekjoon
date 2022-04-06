#include <iostream>
using namespace std;

long long arr[101] = { 0, 1, 1, 1, };

// N��° ���ﰢ�� ã��
long long semo(int n) {
    // �̹� ã�� ���� �ִٸ�
    if (arr[n] != 0)
        return arr[n];

    return arr[n] = semo(n - 2) + semo(n - 3);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        // ���
        cout << semo(N) << "\n";
    }

    return 0;
}