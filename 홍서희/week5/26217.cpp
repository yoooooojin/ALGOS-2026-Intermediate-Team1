#include <bits/stdc++.h>
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    double sum = 0;
    for (double i = 1; i <= N; i++)
    {
        sum += 1 / i;
    }
    cout << fixed;
    cout.precision(4);
    cout << N * sum;
    return 0;
}