#include <iostream>
#include <queue>
using namespace std;

int arr[1000000];

bool check(int n, int F);

bool check(int n, int F) {
    return (n > 0 && n <= F && arr[n] == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int  F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    queue<int> q;
    q.push(S);
    arr[S] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == G) {
            cout << arr[now] - 1 << '\n';
            return 0;
        }

        int next = now + U;
        if (check(next, F)) {
            q.push(next);
            arr[next] = arr[now] + 1;
        }

        next = now - D;
        if (check(next, F)) {
            q.push(next);
            arr[next] = arr[now] + 1;
        }
    }

    cout << "use the stairs\n";

    return 0;
}