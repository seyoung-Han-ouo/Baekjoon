#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct alpha {
    char c;
    int sum = 0;
};

alpha arr[26];

bool compare(alpha a, alpha b);
int sum();

bool compare(alpha a, alpha b) {
    return a.sum > b.sum;
}

int sum() {
    int idx = 0, sum = 0;

    for (int i = 9; i >= 0; i--)
        sum += arr[idx++].sum * i;

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            arr[s[j] - 'A'].c = s[j];
            arr[s[j] - 'A'].sum += pow(10, s.length() - 1 - j);
        }
    }

    sort(arr, arr + 26, compare);

    cout << sum() << '\n';

    return 0;
}