#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    int n;
    cin >> n;
    while (n--)
    {
        int num, pos;
        cin >> num >> pos;
        queue<int> q;
        priority_queue<int, vector<int>, less<int>> pq;
        while (num--)
        {
            int x;
            cin >> x;
            q.push(x);
            pq.push(x);
        }
        int time = 0;
        while (1)
        {
            if (q.front() == pq.top())
            {
                q.pop();
                pq.pop();
                pos--, time++;
                if (pos == (-1))
                {
                    cout << time << endl;
                    break;
                }
                else
                    continue;
            }
            else
            {
                q.push(q.front());
                q.pop();
                pos--;
                if (pos == (-1))
                    pos = q.size() - 1;
                else
                    continue;
            }
        }
    }
    return 0;
}