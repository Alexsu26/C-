#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 85;
int main()
{
    int num;
    cin>>num;
    int s[maxn];
    int cnt = 0;
    while(num--)
    {
        char str[maxn];
        int sum = 0,n = 0;

        cin>>str;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i] == 'o')
                n++;
            sum += n;
            if(str[i+1] != 'O')
                n = 0;
        }
        s[cnt++] = sum;
    }
    for(int i=0;i<cnt;i++)
        cout<<s[i]<<endl;
    return 0;
}
