#include <iostream>
using namespace std;

bool solve(int &W)
{
    int w1, d1, w2, d2;
    cin >> w1 >> d1 >> w2 >> d2;
    bool b1 = true, b2 = true;
    if (!w1)
        solve(w1);
    if (!w2)
        solve(w2);
    W = w1 + w2;
    return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T, W;
    cin >> T;
    while (T--)
    {
        if (solve(W))
            cout << "YES\n";
        else
            cout << "NO\n";
        if (T)
            cout << "\n";
    }
    return 0;
}