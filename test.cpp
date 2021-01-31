#include <bits./stdc++.h>
using namespace std;

struct dot
{
    int x;
    int y;
    bool operator < (const dot& b) const {
        if(x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
}dots[4];

int main()
{
    dots[0].x = 5,dots[0].y = 14;
    dots[1].x = 6,dots[1].y = 10;
    dots[2].x = 5,dots[2].y = 10;
    dots[3].x = 6,dots[3].y = 14;
    cout << "original:\n";
    for(int i=0; i<4; i++)
        cout << dots[i].x << " " << dots[i].y << endl;
    
    cout << "after sort:\n";
    sort(dots,dots+4);
    for(int i=0; i<4; i++)
        cout << dots[i].x << " " << dots[i].y << endl;
    return 0;
}