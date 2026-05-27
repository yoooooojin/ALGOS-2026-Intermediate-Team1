#include <bits/stdc++.h>
using namespace std;

int N;
double dp[7][7][7][1001];
double money[7][7][7];
int tmp[3];

void dfs(int level)
{
    if (level == 3)
    {
        int res = 0;
        if (tmp[0] == tmp[1] && tmp[0] == tmp[2])
        {
            res = 10000 + tmp[1] * 1000;
        }
        else if (tmp[0] == tmp[1])
        {
            res = 1000 + tmp[1] * 100;
        }
        else if (tmp[2] == tmp[1])
        {
            res = 1000 + tmp[1] * 100;
        }
        else if (tmp[0] == tmp[2])
        {
            res = 1000 + tmp[0] * 100;
        }
        else
        {
            res = max(max(tmp[0], tmp[1]), tmp[2]) * 100;
        }
        money[tmp[0]][tmp[1]][tmp[2]] = double(res);
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            tmp[level] = i;
            dfs(level + 1);
        }
    }
}

double recv(int a, int b, int c, int remain)
{
    if (!remain)
        return money[a][b][c];

    double &ret = dp[a][b][c][remain];

    if (ret > -0.5)
        return ret;

    double current_money = money[a][b][c];
    double next_expected = 0;

    for (int i = 1; i <= 6; i++)
        next_expected += recv(b, c, i, remain - 1);

    next_expected /= 6.0;

    ret = max(current_money, next_expected);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    dfs(0);

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            for (int k = 0; k < 7; k++)
                for (int l = 0; l <= N; l++)
                    dp[i][j][k][l] = -1.0;

    double ans = recv(0, 0, 0, N);

    cout << fixed;
    cout.precision(7);
    cout << ans << "\n";

    return 0;
}