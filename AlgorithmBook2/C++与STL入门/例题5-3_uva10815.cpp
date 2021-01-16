#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

set<string> dict;

int main()
{
    string ss, buf;
    while (cin >> ss)
    {
        for (int i = 0; i < ss.length(); i++)
        {
            if (isalpha(ss[i]))
                ss[i] = tolower(ss[i]);
            else
                ss[i] = ' ';
        }
        stringstream s(ss);
        while (s >> buf)
            dict.insert(buf);
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
        cout << *it << endl;
    return 0;
}