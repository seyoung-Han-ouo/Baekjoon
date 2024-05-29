#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (dp.empty() || dp.back() < num) 
            dp.push_back(num);
        else {
            int idx = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
            dp[idx] = num;
        }
    }

    cout << dp.size() << '\n';
    
    return 0;
}