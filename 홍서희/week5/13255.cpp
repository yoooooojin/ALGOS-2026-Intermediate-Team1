#include <bits/stdc++.h>
using namespace std;
int N, K;
double A[51];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++)
        cin >> A[i];
    double p = N, tmp = 0;
    for (int i = 0; i < K; i++)
    {
        tmp += (p * (1 - A[i] / N) + (N - p) * (A[i] / N));
        p = tmp;
    }
    cout << fixed;
    cout.precision(11);
    cout << p;
    return 0;
}