#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<double> p(n);
    double ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        ans += p[i];
    }

    for (int i = 0; i < n - 1; i++) {
        ans += p[i] * (1 - p[i + 1]) + p[i + 1] * (1 - p[i]);
    }

    cout << fixed << setprecision(12) << ans << "\n";

    return 0;
}