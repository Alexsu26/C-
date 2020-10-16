/*
把前 nn（n\leq 10^4n≤10 
 ）个整数顺次写在一起：
 12345678910111213141516....
 数一数 0∼9 分别出现了多少次。
*/
//较多解题思路为将数字存储为字符串，然后通过字符串运算
#include <stdio.h>

#define maxn 10000

int main(void)
{
    int T;
    scanf("%d",&T);
    int num[maxn];
    int n;
    while( T--)
    {
        int count[10];
        for (int i = 0; i < 10; i++)
            count[i] = 0;
        scanf("%d",&n);
        for( int i=1; i<=n; i++)
            num[i] = i;
        for ( int j=1; j<=n; j++)
        {
            while(num[j])
            {
                int x = num[j]%10;
                count[x]++;
                num[j] /= 10; 
            }
        }



        for( int i=0; i<10; i++)
        {
            if( i== 9 )
                printf("%d\n",count[i]);
            else
                printf("%d ",count[i]);
        }
    }
    return 0;
}