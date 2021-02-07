#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 10;
int next[maxn];
char s[maxn];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    // char s[maxn];
    while (scanf("%s", s + 1) == 1)
    {
        int len = strlen(s + 1);
        int cur = 0, last = 0;
        // int next[maxn];
        next[0] = 0;
        for (int i = 1; i <= len; i++)
        {
            char c = s[i];
            if (c == '[')
                cur = 0;
            else if (c == ']')
                cur = last;
            else
            {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last)
                    last = i;
                cur = i;
            }
        }

        for (int i = next[0]; i != 0; i = next[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}