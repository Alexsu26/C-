// 现给你若干个分子式需要你求分子量。
// 例如：C6H5OH的分子量为12 .016 +1.0085 + 16.00 + 1.008 = 94.108g / mol。
// （ps：数字为数字前面元素的下标，所有分子式均无括号例如：2OH = 2 * 16.00 + 1.008）

// 输入输出格式

// 输入：

// 输入n(2 <= n <= 99)

// 接下来n行为分子式

// 输出：

// 输出每个分子的分子式

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxn 105

double z[4] = {12.01, 1.008, 16.00, 14.01};

int main(int argc, char const *argv[])
{
    char str[maxn];
    int T;
    scanf("%d", &T);
    double sum[maxn];
    memset(sum, 0.0, sizeof(sum));
    int cnt = 0;
    while (T--)
    {
        scanf("%s", str);
        double num[4];
        memset(num, 0.0, sizeof(num));
        for (int i = 0; i < strlen(str); i++)
        {
            int flag;
            //switch可直接输出原子质量，不必再用flag、z[]数组占用内存
            switch (str[i])
            {
            case 'C':
                flag = 0;
                break;
            case 'H':
                flag = 1;
                break;
            case 'O':
                flag = 2;
                break;
            case 'N':
                flag = 3;
                break;
            }
            if (isdigit(str[i]))
                continue;
            //判断后两位是否都为数字
            int plus = 1;
            if (isdigit(str[i + 1]))
                if (isdigit(str[i + 2]))
                    plus = (str[i + 1] - '0') * 10 + (str[i + 2] - '0');
                else
                    plus = str[i + 1] - '0';
            //评测中的教好办法
            /*
            int plus = 0;
            while( isdigit(str[i+1]) ){
                plus = plus*10 + str[i+1]-'0';
                i++;
            }
            解决了两次判断问题，并且如果是三位数也能满足
            */
            num[flag] += plus;
        }
        for (int i = 0; i < 4; i++)
            if (num[i])
                sum[cnt] += z[i] * num[i];
        cnt++;
    }

    for (int i = 0; i < cnt; i++)
        printf("%.3f\n", sum[i]);
    return 0;
}
