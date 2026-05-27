#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int len(int n)
{
    int h = 0;
    while (n > 0)
    {
        h++;
        n /= 10;
    }
    return h;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> N)
    {
        int j = N;
        int b = N;
        for (int i = 1; i < N; i++)
        {
            int tj = j * (N - i) + N * b;
            int tb = b * (N - i);
            int g = gcd(tj, tb);
            j = tj / g;
            b = tb / g;
        }
        if (j % b == 0)
            cout << j / b << '\n';
        else
        {
            int d = j / b;
            j %= b;
            for (int i = 0; i < len(d); i++)
            {
                cout << " ";
            }
            cout << " " << j << '\n';
            cout << d << " ";
            for (int i = 0; i < len(b); i++)
            {
                cout << "-";
            }
            cout << '\n';
            for (int i = 0; i < len(d); i++)
            {
                cout << " ";
            }
            cout << " " << b << '\n';
        }
    }
    return 0;
}
