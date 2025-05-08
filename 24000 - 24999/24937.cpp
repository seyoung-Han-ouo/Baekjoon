#include <iostream>
using namespace std;

string s = "SciComLove";

void print(int start, int end);

void print(int start, int end) {
    for (int i = start; i < end; i++) cout << s[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    int n = (N % s.length());

    print(n, s.length());
    print(0, n);
    cout << '\n';

    return 0;
}