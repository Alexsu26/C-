// #include <stdio.h>
// #include <string.h>
#include <bits/stdc++.h>
#define maxn 85
int main()
{
    int T;
    scanf("%d", &T);
    char str[maxn];
    while (T--)
    {
        scanf("%s", str);
        for (int k = 1; k <= strlen(str); k++)
        {
            if (strlen(str) % k == 0)
            {
                char ch[maxn];
                memset(ch, 0, sizeof(ch));
                for (int i = 0; i < k; i++)
                    ch[i] = str[i];
                // printf("ch=%s,strlen(ch)=%d\n", ch, strlen(ch));
                char ch2[maxn];
                strcpy(ch2, ch);
                // printf("ch2=%s,strlen(ch2)=%d\n", ch2, strlen(ch2));
                for (int j = 1; j < strlen(str) / k; j++)
                {
                    strcat(ch2, ch);
                }
                // printf("addstrlen(ch2)=%d\n", strlen(ch2));
                if (!strcmp(ch2, str))
                {
                    printf("%d\n", k);
                    break;
                }
                else
                    continue;
            }
        }
        if(T)
            printf("\n");
    }
    printf("Time Used = %.8fs\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}