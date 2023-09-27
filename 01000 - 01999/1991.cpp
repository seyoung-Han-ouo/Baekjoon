#include <iostream>
using namespace std;

int N;
char tree[26][2];
string pr, in, po;

void order(int n);

void order(int n) {
    if (n < 0 || n >= N) return;

    pr += (char)('A' + n);
    order(tree[n][0] - 'A');

    in += (char)('A' + n);
    order(tree[n][1] - 'A');

    po += (char)('A' + n);
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        cin >> tree[c - 'A'][0] >> tree[c - 'A'][1];
    }

    order(0); 
    cout << pr << '\n' << in << '\n' << po << '\n';

    return 0;
}