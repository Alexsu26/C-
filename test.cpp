#include <iostream>
#include <vector>
using namespace std;

const int maxn = 10000;
int dots[2*maxn][2*maxn];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout); 
    int n;
    cin >> n;
    while(n--)
    {
        for(int i=0; i<2*maxn; i++)
            for(int j=0; j<2*maxn; j++)
                dots[i][j] = 0;
        int num;
        cin >> num;
        int minx=maxn,miny=maxn,maxx=0,maxy=0;
        while(num--)
        {
            int x,y;
            cin >> x >> y;
            dots[x+maxn][y+maxn] = 1;
            minx = min(minx,x);
            maxx = max(maxx,x);
            miny = min(miny,y);
            maxy = max(maxy,y);
        }
        minx += maxn;
        maxx += maxn;
        miny += maxn;
        maxy += maxn;
        vector<double>symm;
        bool flag = true;
        for(int i=minx; i<=maxx; i++)
        {
            vector<int>lines;
            for(int j=miny; j<=maxy; j++)
            {
                if(dots[i][j] == 1)
                    lines.push_back(dots[i][j]);
            }
            if(lines.size() % 2 == 0)
            {
                double sum = 0;
                for(int i=0; i<lines.size(); i++)
                    sum += lines[i];
                symm.push_back(sum/2.0);
            }
            else
            {
                int i;
                for(i=0; i<lines.size()/2; i++)
                {
                    if(lines[i] != lines[lines.size() - i])
                    {
                        flag = false;
                        break;
                    }
                    symm.push_back(lines[i]);
                }
            }
        }
        for(int j=0; j<symm.size() - 1; j++)
            if(symm[j] != symm[j+1])
            {
                flag = false;
                break;
            }
        
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}