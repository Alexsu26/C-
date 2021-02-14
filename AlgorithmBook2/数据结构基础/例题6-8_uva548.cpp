#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxv = 10000 + 10;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_input(int *a)
{
    string line;
    if (!getline(cin, line))
        return false;
    stringstream ss(line);
    n = 0;
    int x;
    while (ss >> x)
        a[n++] = x;
    return true;
}

int build_tree(int L1, int R1, int L2, int R2)
{
    if (L1 > R1)
        return 0;
    int root = post_order[R2];
    int p = 0;
    while (in_order[p] != root)
        p++;
    int cnt = p - L1;
    lch[root] = build_tree(L1, p - 1, L2, L2 + cnt - 1);
    rch[root] = build_tree(p + 1, R1, L2 + cnt, R2 - 1);
    return root;
}

int best, best_sum;
void bfs(int root, int sum)
{
    sum += root;
    if (!lch[root] && !rch[root])
        if (sum < best_sum || (sum == best_sum && root < best))
        {
            best = root;
            best_sum = sum;
        }
    if (lch[root])
        bfs(lch[root], sum);
    if (rch[root])
        bfs(rch[root], sum);
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    while (read_input(in_order))
    {
        read_input(post_order);
        build_tree(0, n - 1, 0, n - 1);
        best_sum = 100000;
        bfs(post_order[n - 1], 0);
        printf("%d\n", best);
    }
    return 0;
}