#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int maxn = 1000 + 10;
vector<string> code[maxn];
int length[maxn];

void printnull(const string &s, int long_str)
{
    cout << s;
    for (int i = 0; i < long_str - s.size() + 1; i++)
        cout << " ";
}
int main()
{
    std::ios_base::sync_with_stdio(false); //关闭同步
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int cnt = 0;
    string str;
    //输入部分
    while (getline(cin, str, '\n'))
    {
        stringstream line(str);
        string x;
        int j = 0;
        while (line >> x)
        {
            code[cnt].push_back(x);
            length[j] = max(length[j], (int)x.size());
            j++;
        }
        cnt++;
    }

    //输出
    for (int i = 0; i < cnt; i++)
    {
        int j;
        for (j = 0; j < code[i].size() - 1; j++)
        {
            printnull(code[i][j], length[j]);
        }
        cout << code[i][j] << endl;
    }

    return 0;
}