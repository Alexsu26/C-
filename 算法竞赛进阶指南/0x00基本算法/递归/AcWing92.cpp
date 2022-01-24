#include <cstdio>
#include <vector>

using namespace std;

int n;

vector<int> chosed;

void calc(int x)
{
    if (x == n + 1)
    {
        for (int i = 0; i < chosed.size(); i++)
        {
            printf("%d ", chosed[i]);
        }
        printf("\n");
        return;
    }
    //not chosed
    calc(x + 1);

    //chosed
    chosed.push_back(x);
    calc(x + 1);

    chosed.pop_back();
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    calc(1);
    return 0;
}
