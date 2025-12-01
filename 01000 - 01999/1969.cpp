#include <iostream>
#include <map>
using namespace std;

int N, M;
string arr[1001];
char dna[4] = { 'A', 'C', 'G', 'T' };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int mn = 0;
    string result = "";

    for (int i = 0; i < M; i++) {
        map<char, int> cnt;

        for (int j = 0; j < N; j++) cnt[arr[j][i]]++;

        int idx = 0;
        for (int j = 1; j < 4; j++) {
            if (cnt[dna[j]] > cnt[dna[idx]]) idx = j;
        }

        result += dna[idx];
        mn += (N - cnt[dna[idx]]);
    }

    cout << result << '\n' << mn << '\n';

    return 0;
}