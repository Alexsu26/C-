#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100 + 10;
char oil[maxn][maxn];
int idx[maxn][maxn], cnt;
int m, n;

void bfs(int r, int c, int id)
{
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;
    if (idx[r][c] != 0 || oil[r][c] != '@')
        return;
    idx[r][c] = id;
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (i != 0 || j != 0)
                bfs(r + i, c + j, id);
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    while (cin >> m >> n && m && n)
    {
        for (int i = 0; i < m; i++)
            cin >> oil[i];

        memset(idx, 0, sizeof(idx));
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (oil[i][j] == '@' && idx[i][j] == 0)
                    bfs(i, j, ++cnt);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}