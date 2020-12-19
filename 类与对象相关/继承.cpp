#include <bits.\stdc++.h>
using namespace std;

//基类,平行四边形
class Parallelogram
{
    public:
    void setWidth(int wid){
        width = wid;
    }
    void setHeight(int hei){
        height = hei;
    }
    protected:
    int width;
    int height;
};
//基类，面积
class cost
{
    public:
    int areacost(int area){
        return 50*area;
    }
};
//派生类，长方形
class rectangle :public Parallelogram,public cost
{
    public:
    int getArea(){
        return (width * height);
    }
};

int main()
{
    rectangle rect;
    //派生类可以继承基类的成员
    rect.setWidth(15);
    rect.setHeight(20);
    cout<<"rectangle area: "<< rect.getArea() << endl;

    int cost = rect.areacost(rect.getArea());
    cout<<"area cost: "<< cost << endl;
    return 0;
}
