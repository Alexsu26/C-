// 输入正整数n以及n个文件名，
// 排序后按列优先的方式左对齐输出。
// 假设最长文件名有M字符，
// 则最右边有M字符，
// 其他列都是M+2字符。
#include <bits.\stdc++.h>
using namespace std;

const int maxcol = 60;
const int maxn = 100 + 50;
string filename[maxn];

//将s输出，不足位数补空格
void print(const string &s, int len, char x)
{
    cout << s;
    for (int i = 0; i < len - s.length(); i++)
    {
        cout << x;
    }
}

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n;
    while (cin >> n)
    {
        int M = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> filename[i];
            //确定最大字符串宽度
            M = max(M, (int)filename[i].length());
        }
        //n-1是为防止n%cols==0后多＋1
        int cols = (maxcol - M) / (M + 2) + 1;
        int rows = (n - 1) / cols + 1;
        print("", maxcol, '-');
        cout << "\n";
        //排序
        sort(filename, filename + n);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                //横向打印，列数乘总行数
                int loc = c * rows + r;
                if (loc < n)
                    print(filename[loc], c == (cols - 1) ? M : M + 2, ' ');
            }
            cout << "\n";
        }
    }
    return 0;
}