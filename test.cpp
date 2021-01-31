#include <bits./stdc++.h>
using namespace std;

const int maxn = 10000;
int dots[2*maxn][2*maxn];
int main()
{
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
        for(int i=minx-1; i<maxx+1; i++)
        {
            vector<int>lines;
            for(int j=miny-1; j<maxy+1; j++)
            {
                if(dots[i][j] == 1)
                    lines.push_back(dots[i][j]);
            }
            if(lines.size() % 2 == 0)
            {

            }
            else
            {
                
            }
        }
    }
    return 0;
}