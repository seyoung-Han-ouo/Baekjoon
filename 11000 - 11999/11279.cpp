#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue <int> heap;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (heap.empty()) heap.push(x);

            cout << heap.top() << '\n';
            heap.pop();
        }
        else heap.push(x);
    }

    return 0;
}