#include <iostream>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;

int FindId(Set x)
{
    if(IDcache.count(x))
        return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}
int main(int argc, char const *argv[])
{
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int flag;
    cin >> flag;
    while(flag--)
    {
        stack<int> s;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string op;
            cin >> op;
            if (op[0] == 'P')
                s.push(FindId(Set()));
            else if (op[0] == 'D')
                s.push(s.top());
            else
            {
                Set x1 = Setcache[s.top()];
                s.pop();
                Set x2 = Setcache[s.top()];
                s.pop();
                Set x;
                if (op[0] == 'U')
                    set_union(ALL(x1), ALL(x2), INS(x));
                if (op[0] == 'I')
                    set_intersection(ALL(x1), ALL(x2), INS(x));
                if (op[0] == 'A')
                {
                    x = x2;
                    x.insert(FindId(x1));
                }
                s.push(FindId(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***\n";
    }
    return 0;
}