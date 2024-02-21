#include <iostream>
using namespace std;

struct Country
{
    int id;
    int gold;
    int silver;
    int bronze;
};

Country ck, arr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].id >> arr[i].gold >> arr[i].silver >> arr[i].bronze;

        if (arr[i].id == K) ck = arr[i];
    }

    int rank = 1;

    for (int i = 0; i < N; i++) {
        Country a = arr[i];

        if (a.gold == ck.gold) {
            if (a.silver == ck.silver) {
                if (a.bronze > ck.bronze) rank++;
            }
            else if (a.silver > ck.silver) rank++;
        }
        else if (a.gold > ck.gold) rank++;
    }

    cout << rank << '\n';

    return 0;
}