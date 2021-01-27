#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        queue<int> card;
        for (int i = 1; i <= n; i++)
            card.push(i);

        cout << "Discarded cards:";
        bool flag = true;
        while (card.size() != 1)
        {
            if (flag)
            {
                cout << " ";
                flag = false;
            }
            else
                cout << ", ";
            cout << card.front();
            card.pop();
            card.push(card.front());
            card.pop();
        }
        cout << "\nRemaining card: " << card.front() << endl;
    }
    return 0;
}