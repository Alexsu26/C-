//线性方法，复杂度为O（N）
#include <bits./stdc++.h>
using namespace std;

int MaxSubseqSum4(vector<int> A, int N)
{
    int Thissum = 0, Maxsum = 0;
    int i;
    for (i = 0; i < N; i++)
    {
        Thissum = A[i] + Thissum;
        if (Thissum > Maxsum)
            Maxsum = Thissum;
        else if (Thissum < 0)
            Thissum = 0;
    }
    return Maxsum;
}

vector<int> sum;
int main()
{
    freopen("test.in", "r", stdin);
    int x;
    while (cin >> x)
        sum.push_back(x);
    cout << MaxSubseqSum4(sum, sum.size()) << endl;

    return 0;
}