#include <bits.\stdc++.h>
using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int main(int argc, char const *argv[])
{
    char a[] = "wjdupsjpvt";
    char b[] = "tvpjspudjw";
    qsort(a,10,1,*cmp);
    qsort(b,10,1,*cmp);
    cout<<a<<endl<<b<<endl;
    return 0;
}
