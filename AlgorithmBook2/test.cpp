#include <bits.\stdc++.h>
using namespace std;

class Box
{
    double* length;
public:
    double getlen(){
        return *length;
    }
    Box(double len){
        cout<<"调用构造函数初始化成员变量\n" ;
        length = new double;
        *length = len;
    }
    Box(const Box &Obj){
        cout<< "调用拷贝构造函数并未length分配内存\n";
        length = new double;
        *length = *Obj.length;
    }
    ~Box(){
        cout<<"调用析构函数删除对象\n";
        delete length;
    }
};
void setlen(Box obj)
{
    cout << "box 大小为： " << obj.getlen() << endl;
}
int main()
{
    Box Box(12.2);
    setlen(Box);
    return 0;
}