#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        int n;
        scanf("%d", &n);

        sum += n;
    }

    printf("%d\n%d", sum / 60, sum % 60);

    return 0;
}