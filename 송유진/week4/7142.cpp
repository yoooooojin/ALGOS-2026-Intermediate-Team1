#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "100 99\n";
    for (int i = 99; i >= 1; i--) {
        cout << i << " " << i + 1 << " 1\n";
    }

    return 0;
}