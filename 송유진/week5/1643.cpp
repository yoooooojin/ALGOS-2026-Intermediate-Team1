#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    while (cin >> n) {
        long long A = 0;
        long long B = 1;

        for (long long i = 1; i <= n; i++) {
            long long next_B = (B / gcd(B, i)) * i;
            long long next_A = A * (next_B / B) + n * (next_B / i);
            long long g = gcd(next_A, next_B);
            A = next_A / g;
            B = next_B / g;
        }

        long long X = A / B;
        A %= B;

        if (A == 0) {
            cout << X << "\n";
        }
        else {
            int x_len = to_string(X).length();
            int b_len = to_string(B).length();

            cout << string(x_len + 1, ' ') << A << "\n";
            cout << X << " " << string(b_len, '-') << "\n";
            cout << string(x_len + 1, ' ') << B << "\n";
        }
    }

    return 0;
}