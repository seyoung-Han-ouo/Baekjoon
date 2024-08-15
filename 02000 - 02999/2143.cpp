#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int T, n, m, num[1001];
vector<long long> aSum;
unordered_map<long long, int> bSum;

void makeASum();
void makeBSum();

void makeASum() {
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += num[j];
            aSum.push_back(sum);
        }
    }
}

void makeBSum() {
    for (int i = 0; i < m; i++) {
        int sum = 0;

        for (int j = i; j < m; j++) {
            sum += num[j];
            bSum[sum]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T >> n;
    for (int i = 0; i < n; i++) cin >> num[i];

    makeASum();

    cin >> m;
    for (int i = 0; i < m; i++) cin >> num[i];

    makeBSum();

    long long result = 0;

    for (int i = 0; i < aSum.size(); i++) {
        if (bSum.find(T - aSum[i]) != bSum.end())
            result += bSum[T - aSum[i]];
    }

    cout << result << '\n';

    return 0;
}