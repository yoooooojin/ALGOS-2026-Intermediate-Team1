#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double R[7][7][7];
double V[2][7][7][7];

double get_reward(int a, int b, int c) {
    if (a == b && b == c) {
        return 10000.0 + a * 1000.0;
    }
    if (a == b || a == c) {
        return 1000.0 + a * 100.0;
    }
    if (b == c) {
        return 1000.0 + b * 100.0;
    }
    return max({ a, b, c }) * 100.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int a = 1; a <= 6; ++a) {
        for (int b = 1; b <= 6; ++b) {
            for (int c = 1; c <= 6; ++c) {
                R[a][b][c] = get_reward(a, b, c);
                V[0][a][b][c] = R[a][b][c];
            }
        }
    }

    for (int k = 1; k <= n - 3; ++k) {
        int curr = k % 2;
        int prev = (k - 1) % 2;
        for (int a = 1; a <= 6; ++a) {
            for (int b = 1; b <= 6; ++b) {
                for (int c = 1; c <= 6; ++c) {
                    double expected_next = 0;
                    for (int d = 1; d <= 6; ++d) {
                        expected_next += V[prev][b][c][d];
                    }
                    expected_next /= 6.0;
                    V[curr][a][b][c] = max(R[a][b][c], expected_next);
                }
            }
        }
    }

    double ans = 0;
    int target = (n - 3) % 2;
    for (int a = 1; a <= 6; ++a) {
        for (int b = 1; b <= 6; ++b) {
            for (int c = 1; c <= 6; ++c) {
                ans += V[target][a][b][c];
            }
        }
    }
    ans /= 216.0;

    cout << fixed << setprecision(12) << ans << "\n";

    return 0;
}