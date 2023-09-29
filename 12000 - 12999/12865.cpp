#include <iostream>
using namespace std;

int bag[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;

        for (int j = K; j >= W; j--)
            bag[j] = max(bag[j], bag[j - W] + V);
    }

    cout << bag[K] << '\n';

    return 0;
}