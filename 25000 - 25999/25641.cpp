#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string st;
    
    cin >> N >> st;

    int s = 0; // 소세지의 수
    int t = 0; // 떡의 수

    // 소세지와 떡의 수 구하기
    for (int i = 0; i < N; i++) {
        if (st[i] == 's') s++;
        else t++;
    }

    // 균형 잡힌 소떡소떡 만들기
    int idx = 0;
    for (int i = 0; i < N; i++) {
        if (s == t) {
            idx = i;
            break;
        }

        if (st[i] == 's') s--;
        else t--;
    }

    // 출력
    for (int i = idx; i < N; i++) cout << st[i];
    cout << '\n';

    return 0;
}