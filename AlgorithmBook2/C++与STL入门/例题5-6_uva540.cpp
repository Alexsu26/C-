#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
#include <map>
using namespace std;

const int maxn = 1000 + 10;
int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int t, flag = 0;
    while (scanf("%d", &t) == 1 && t)
    {
        cout << "Scenario #" << ++flag << endl;

        //存储各个队伍的人的编号
        map<int, int> team;
        for (int i = 0; i < t; i++)
        {
            int x, n;
            cin >> n;
            while (n--)
            {
                cin >> x;
                team[x] = i;
            }
        }

        queue<int> q, q2[maxn];
        //模拟命令
        for (;;)
        {
            string s;
            int x;
            cin >> s;
            if (s[0] == 'S')
                break;
            else if (s[0] == 'D')
            {
                int t = q.front();
                cout << q2[t].front() << endl;
                q2[t].pop();
                if (q2[t].empty())
                    q.pop();
            }
            else if (s[0] == 'E')
            {
                cin >> x;
                int t = team[x];
                if (q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        cout << "\n";
    }

    return 0;
}