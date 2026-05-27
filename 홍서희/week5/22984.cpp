#include <bits/stdc++.h>
using namespace std;
int N, ans = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<int> parr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> parr[i];
        ans += parr[i];
    }
    for (int i = 1; i < N; i++)
    {
        ans += (parr[i - 1] * (1 - parr[i]) + (1 - parr[i - 1]) * parr[i]);
    }
    cout << fixed;
    cout.precision(7);
    cout << ans;
    return 0;
}