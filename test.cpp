#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    set<string>dict;
    string s;
    while(cin >> s)
    {
        dict.insert(s);
    }
    for(set<string>::iterator it = dict.begin(); it != dict.end(); it++)
    {
        string str = *it;
        for(int i=1; i != str.size(); i++)
        {
            if( dict.count(str.substr(0,i)) && dict.count(str.substr(i)))
            {
                cout << str << endl;
                break;
            }    
        }
    }
    return 0;
}