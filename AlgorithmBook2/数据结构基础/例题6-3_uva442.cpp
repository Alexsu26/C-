#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Matrix
{
    int row, col;
    Matrix(int row = 0, int col = 0) : row(row), col(col) {}
} m[26];

stack<Matrix> s;

int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int j = str[0] - 'A';
        cin >> m[j].row >> m[j].col;
    }

    string str;
    while (cin >> str)
    {
        int ans = 0;
        bool error = false;
        for (int i = 0; i < str.length(); i++)
        {
            if (isalpha(str[i]))
            {
                s.push(m[str[i] - 'A']);
            }
            else if (str[i] == ')')
            {
                Matrix m2 = s.top();
                s.pop();
                Matrix m1 = s.top();
                s.pop();
                if (m1.col != m2.row)
                {
                    error = true;
                    break;
                }
                ans += m1.row * m1.col * m2.col;
                s.push(Matrix(m1.row, m2.col));
            }
        }
        if (error)
            cout << "error\n";
        else
            cout << ans << endl;
    }

    return 0;
}
