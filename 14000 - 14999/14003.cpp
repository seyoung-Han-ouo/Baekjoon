#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define MAX 1000001

int arr[MAX];
int seat[MAX];
vector<int> dp;
stack<int> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if (dp.empty() || dp.back() < arr[i]) dp.push_back(arr[i]);

        int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        dp[idx] = arr[i];
        seat[i] = idx;
    }

    int find = dp.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (seat[i] == find) {
            result.push(arr[i]);
            find--;
        }
    }

    cout << dp.size() << '\n';
    while (!result.empty()) {
        cout << result.top() << ' ';
        result.pop();
    }

    return 0;
}