#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Jewel {
    int weight = 0; // 무게
    int price = 0;  // 가격
};

int N, K, now = 0;
Jewel jewel[300001];
int bag[300001];
priority_queue<pair<int, int>> canPut;

bool compare(Jewel a, Jewel b);
int putJewel(int bag);

bool compare(Jewel a, Jewel b) {
    if (a.weight == b.weight) return a.price > b.price;
    return a.weight < b.weight;
}

int putJewel(int bag) {
    while (true) {
        if (now >= N) break;

        if (jewel[now].weight > bag) break;

        canPut.push({ jewel[now].price, jewel[now].weight });
        now++;
    }

    if (canPut.empty()) return 0;
    else {
        int result = canPut.top().first;
        canPut.pop();

        return result;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;

        jewel[i] = { m, v };
    }

    for (int i = 0; i < K; i++) cin >> bag[i];

    sort(jewel, jewel + N, compare);
    sort(bag, bag + K);

    long long result = 0;
    for (int i = 0; i < K; i++) result += putJewel(bag[i]);

    cout << result << '\n';

    return 0;
}