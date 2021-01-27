#include <iostream>
#include <algorithm>
using namespace std;

void loop(int *A, int len)
{
    int a0 = A[0];
    int i;
    for (i = 0; i < len - 1; i++)
        A[i] = abs(A[i] - A[i + 1]);
    A[i] = abs(A[i] - a0);
}

int main()
{
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    const int maxn = 15 + 5;
    int Ducci[maxn];
    int n, num;
    cin >> n;
    while (n--)
    {
        cin >> num;
        for (int i = 0; i < num; i++)
            cin >> Ducci[i];

        for (int i = 0; i < 1005; i++)
            loop(Ducci, num);

        bool flag = true;
        for (int i = 0; i < num; i++)
        {
            if (Ducci[i] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "ZERO\n";
        else
            cout << "LOOP\n";
    }
    return 0;
}