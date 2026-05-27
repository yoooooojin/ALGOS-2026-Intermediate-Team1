#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    double p = 0.0;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        double flip_prob = (double)a / n;
        p = p * (1.0 - flip_prob) + (1.0 - p) * flip_prob;
    }

    cout << fixed << setprecision(12) << n * p << "\n";

    return 0;
}