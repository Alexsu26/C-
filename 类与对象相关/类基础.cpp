#include <bits.\stdc++.h>
using namespace std;
class Box
{
    //未区别的变量都是private
    double *length;

public:
    //静态成员数据objectCount，在class中声明，class外定义
    static int objectCount;
    //友元函数，声明放在class内部，可使用private的变量
    friend void setlen(Box obj);
    friend double Max(Box obj, double y);

    double getlen()
    {
        return *length;
    }
    //构造函数，对象被创建时调用；double len = 1.0 表明若未初始化len则赋值为1.0
    Box(double len = 1.0)
    {
        cout << "调用构造函数初始化成员变量\n";
        length = new double;
        *length = len;
        //每多一个对象则objectCount+1
        objectCount++;
    }
    //拷贝构造函数，暂时用处未知
    Box(const Box &Obj)
    {
        cout << "调用拷贝构造函数并为length分配内存\n";
        length = new double;
        *length = *Obj.length;
    }
    //析构函数，对象清除时调用
    ~Box()
    {
        cout << "调用析构函数删除对象\n";
        delete length;
    }
    double volume()
    {
        return pow(*length, 3.0);
    }
    int compare(Box box)
    {
        //this指针，用于指向类中的除静态函数的对象（包括函数）
        return this->volume() > box.volume();
    }
    //静态成员函数
    static int printObjNum()
    {
        //return this->objectCount;出错，this只能用于非静态函数内部
        return objectCount; //静态成员函数可以访问静态成员数据
    }
};
//静态成员数据初始化在class外部
int Box::objectCount = 0;
//可以将类作为参数传递给函数并使用.运算符
void setlen(Box obj)
{
    cout << "box 大小为： " << *obj.length << endl;
}
//内联函数，类似于define，调用时直接将函数体置换调用处语句，用于短函数，不能循环
inline double Max(Box obj, double y)
{
    return max(*obj.length, y);
}
int main()
{
    cout << "orignal Obj Num: " << Box::printObjNum() << endl;
    //定义两个对象
    Box Box1(12.2);
    Box Box2(13.1);

    if (Box1.compare(Box2))
        cout << "Box2 < Box1\n";
    else
        cout << "Box2 >= Box1\n";

    setlen(Box1);
    //调用内联函数Max
    double num = 15.2;
    cout << "max of class Box1 and num is: " << Max(Box1, num) << endl;
    //类可以定义指针，但只能先声明，再定义，通过->使用类的内部对象
    Box *ptrbox;
    ptrbox = &Box1;
    cout << "volume of Box1: " << ptrbox->volume() << endl;

    ptrbox = &Box2;
    cout << "volume of Box2: " << ptrbox->volume() << endl;

    cout << "Total objects: " << Box::objectCount << endl;

    cout << "final Obj Num: " << Box::printObjNum() << endl;
    return 0;
}