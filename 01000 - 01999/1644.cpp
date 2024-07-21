#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> sosu;
bool num[4000001];

int findMakeSum();

int findMakeSum() {
    int cnt = 0;
    int sum = 0;
    int start = 0;

    for (int i = 0; i < sosu.size(); i++) {
        sum += sosu[i];

        while (sum > N) sum -= sosu[start++];

        if (sum == N) cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 2; i <= N; i++) {
        if (num[i]) continue;

        for (int j = i * 2; j <= N; j += i) num[j] = true;

        if (!num[i]) sosu.push_back(i);
    }

    cout << findMakeSum() << '\n';

    return 0;
}