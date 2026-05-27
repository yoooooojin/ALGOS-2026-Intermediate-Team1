#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (double)n / i;
    }

    cout << fixed << setprecision(12) << ans << "\n";

    return 0;
}