#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int num;
    while ((cin >> num) && num)
    {
        int A, B;
        vector<int> sa, sb;
        while (num--)
        {
            cin >> A >> B;
            sa.push_back(A);
            sb.push_back(B);
        }

        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());

        if (sa == sb)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}