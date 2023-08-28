#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[15];
bool isVowel[15];

void vowelCheck();
void dfs(int cnt, int now, int mo, int za, string s);

// 모음 표시
void vowelCheck() {
    char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i] == vowel[j]) {
                isVowel[i] = true;
                break;
            }
        }
    }
}

void dfs(int cnt, int now, int mo, int za, string s) {
    if (cnt == L && mo > 0 && za > 1) {
        cout << s << "\n";
        return;
    }

    for (int i = now; i < C; i++) {
        if (isVowel[i])
            dfs(cnt + 1, i + 1, mo + 1, za, s + arr[i]);
        else
            dfs(cnt + 1, i + 1, mo, za + 1, s + arr[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;
    for (int i = 0; i < C; i++) cin >> arr[i];

    sort(arr, arr + C);

    vowelCheck();

    dfs(0, 0, 0, 0, "");

    return 0;
}