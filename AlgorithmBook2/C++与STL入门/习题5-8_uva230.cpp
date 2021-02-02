#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct lib
{
    string bookname;
    string author;
    char x = 'O';
    bool operator<(const lib &b)
    {
        if (author == b.author)
            return bookname < b.bookname;
        return author < b.author;
    }
};

int find(vector<lib> &s, string &str)
{
    int i = 0;
    for (i = 0; i < s.size(); i++)
        if (s[i].bookname == str)
            break;
    return i;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    vector<lib> sys;
    lib book;
    string s;
    int cnt = 0;
    while (getline(cin, s))
    {
        if (s == "END")
            break;
        int index = s.find("by");
        book.bookname = s.substr(0, index - 1);
        book.author = s.substr(index + 3);
        sys.push_back(book);
        cnt++;
    }
    sort(sys.begin(), sys.end());
    string op, bkname;
    while (getline(cin, s))
    {
        if (s == "END")
            break;
        if (s[0] != 'S')
        {
            op = s.substr(0, 6);
            bkname = s.substr(7);
        }
        else
            op = s;
        if (op[0] == 'B')
        {
            sys[find(sys, bkname)].x = 'B';
        }
        else if (op[0] == 'R')
        {
            sys[find(sys, bkname)].x = 'R';
        }
        else if (op[0] == 'S')
        {
            for (int i = 0; i < cnt; i++)
            {
                if (sys[i].x == 'R')
                {
                    int j;
                    for (j = i - 1; j >= 0; j--)
                    {
                        if (sys[j].x == 'O')
                        {
                            cout << "Put " << sys[i].bookname << " after " << sys[j].bookname << endl;
                            sys[i].x = 'O';
                            break;
                        }
                    }
                    if (j < 0)
                    {
                        cout << "Put " << sys[i].bookname << " first" << endl;
                        sys[i].x = 'O';
                    }
                }
            }
            cout << "END\n";
        }
    }
    return 0;
}