#include <iostream>
using namespace std;

int N, mx;
int player[100001];
int card[1000001];
bool check[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> player[i];

        check[player[i]] = true;
        mx = max(mx, player[i]);
    }

    for (int i = 0; i < N; i++) {
        int nowCard = player[i];

        for (int j = nowCard * 2; j <= mx; j += nowCard) {
            if (check[j]) {
                card[nowCard]++;
                card[j]--;
            }
        }
    }

    for (int i = 0; i < N; i++) cout << card[player[i]] << ' ';
    cout << '\n';

    return 0;
}