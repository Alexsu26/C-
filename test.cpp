#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int n,m; //行列数
int num[10010][15];    //数组
typedef pair<int,int> P;
map<string,int> Idcache;  //数组元素的代号
map<P,int> ans;            //最终每行的编号
int cnt = 0;               //id计数

int id(const string &str)
{
    if(Idcache.count(str))
        return Idcache[str];
    else
        return Idcache[str] = ++cnt;
}

int main()
{
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    while(cin >> n >> m)
    {
        Idcache.clear(),cnt=0; //清零
        getchar();   //输入流中的\n

        //输入
        for(int i=0; i<n; i++)
        {
            string str;
            for (int j = 0; j < m - 1; j++)
            {
                getline(cin, str , ',');
                num[i][j] = id(str);
            }
            getline(cin , str, '\n');
            num[i][m-1] = id(str); //最后一个输入单独处理
        }

        //输出
        bool flag = false;
        for(int j=0; j<m-1; j++)
        {
            for(int k=j+1; k<m; k++)
            {
                ans.clear();
                for(int i=0; i<n; i++)
                {
                    int idj = num[i][j];
                    int idk = num[i][k];
                    if(ans.count(P(idj,idk)))
                    {
                        printf("NO\n%d %d\n%d %d\n",ans[P(idj,idk)]+1,i+1,j+1,k+1);
                        flag = true;
                        break;
                    }
                    else
                    {
                        ans[P(idj,idk)] = i;
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(!flag)
            printf("YES\n");
    }
    return 0;
}