#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        // 좌측의 빈공간
        for (int j = 0; j < N - i; j++) cout << ' ';

        // 양끝에 *찍기
        for (int j = 0; j < i * 2 - 1; j++) {
            if (j == 0 || j == i * 2 - 2) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    // 삼각형의 밑면
    for (int i = 0; i < N * 2 - 1; i++) cout << '*';
    
    return 0;
}