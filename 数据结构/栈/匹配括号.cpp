#include <bits./stdc++.h>
using namespace std;

bool CheckBalancedParentheses(string str)
{
    int n = str.length();
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else
        {
            if (s.empty() || s.top() != '(')
                return false;
            else
                s.pop();
        }
    }
    return s.empty() ? true : false;
}

int main()
{
    string str;
    cout << "input str : ";
    cin >> str;
    if (CheckBalancedParentheses(str))
        cout << "Yes!\n";
    else
        cout << "N0!\n";
}