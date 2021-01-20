#include <iostream>
#include <set>
#include <queue>
// #include <vector>
using namespace std;

typedef long long LL;
const int n[3] = {2, 3, 5};
int main()
{
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    set<LL> num;
    pq.push(1);
    num.insert(1);

    for (int i = 1;; i++)
    {
        if (i == 1500)
        {
            cout << "The 1500'th ugly number is "
                 << pq.top() << ".\n";
            break;
        }
        LL x = pq.top();
        pq.pop();
        for (int j = 0; j < 3; j++)
        {
            LL x1 = x * n[j];
            if (!num.count(x1))
            {
                num.insert(x1);
                pq.push(x1);
            }
        }
    }
    return 0;
}