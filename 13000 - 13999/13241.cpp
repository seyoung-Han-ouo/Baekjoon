#include <iostream>
using namespace std;

long long int euclidean(long long int A, long long int B);

long long int euclidean(long long int A, long long int B) {
    while (B > 0) {
        long long int temp = A;
        A = B;
        B = temp % B;
    }

    return A;
}

int main() {
    long long int A, B;
    cin >> A >> B;

    cout << A * B / euclidean(A, B) << '\n';

    return 0;
}