#include <bits.\stdc++.h>
using namespace std;
class Box
{
    double* length;
public:
    static int objectCount;
    friend void setlen( Box obj);
    friend double Max(Box obj, double y);
    double getlen(){
        return *length;
    }
    Box(double len = 1.0){
        cout<<"调用构造函数初始化成员变量\n" ;
        length = new double;
        *length = len;
        objectCount++;
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
    double volume(){
        return pow(*length,3.0);
    }
    int compare(Box box){
        return this->volume() > box.volume();
    }
    static int printObjNum(){
        //return this->objectCount;出错，this只能用于非静态函数内部
        return objectCount;//静态成员函数可以访问静态成员数据
    }
};
int Box::objectCount = 0;
void setlen(Box obj)
{
    cout << "box 大小为： " << *obj.length << endl;
}
inline double Max(Box obj, double y){
    return max(*obj.length,y);
}
int main()
{
    cout<<"orignal Obj Num: " << Box::printObjNum() <<endl;
    Box Box1(12.2);
    Box Box2(13.1);
    
    if(Box1.compare(Box2))
        cout<<"Box2 < Box1\n";
    else
        cout<<"Box2 >= Box1\n";
    
    setlen(Box1);
    
    double num = 15.2;
    cout<<"max of class Box1 and num is: "<<Max(Box1,num) << endl;
    
    Box *ptrbox;
    ptrbox = &Box1;
    cout<< "volume of Box1: " << ptrbox->volume() <<endl;

    ptrbox = &Box2;
    cout<< "volume of Box2: " <<ptrbox->volume() <<endl;

    cout<< "Total objects: " << Box::objectCount << endl;
    
    cout<<"final Obj Num: " << Box::printObjNum() <<endl;
    return 0;
}