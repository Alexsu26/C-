#include <bits.\stdc++.h>
using namespace std;

class Box
{
    public:
    //函数重载，同名函数但是参数不同，不能仅为返回值不同
    void setBox(int len,int wid){
        length = len;
        width = wid;
    }
    void setBox(int hei){
        height = hei;
    }
    void print(){
        cout<< "len: " << length <<
        "\twid: " << width << "\thei: " << height<<endl;
    }
    void countVol(){
        volume = length * width * height;
    }
    int printVol(){
       return volume; 
    }
    //重载 + 运算符
    Box operator+(const Box& b)
    {
        Box box;
        box.height = this->height + b.height;
        box.length = this->length + b.length;
        box.width = this->width + b.width;
        return box;
    }
    //重载++前缀运算符
    Box operator++(){
        height++;
        width++;
        length++;
    }
    //重载++后缀运算符，int表示与前缀的区分
    Box operator++(int){
        Box rec;
        rec = *this;
        height++;
        width++;
        length++;
        return rec;
    }
    //重载 < 运算符
    bool operator<(const Box& b){
        if(volume < b.volume)
            return true;
        return false;
    }
    //重载 << 输出，用友元函数方便用cout输出
    friend ostream &operator<<( ostream &output,
    const Box& a){
        output << "len: " << a.length << 
        "\twid: " << a.width << "\thei: " 
        << a.height << "\tvolume: " << a.volume;
    }
    //重载 >> 输入，用友元方便用cin
    friend istream &operator>>(istream &input,
    Box& a){
        input >> a.length >> a.width >> a.height;
        return input;
    }
    //重载 = 
    void operator=(const Box& a){
        length = a.length;
        width = a.width;
        height = a.height;
    }
    //重载 () ,相当于函数
    Box operator()(int a,int b,int c){
        Box box;
        box.length = length * a;
        box.width = width * b;
        box.height = height *c;
        //volume赋值出错，因为L69重载了=，且为定义volume的=
        //int max = a*b*c;
        //box.volume = volume * max;
        return box;
    }
    private:
    int length;
    int width;
    int height;
    int volume;
};

int main()
{
    Box box1;
    Box box2;
    Box box3;

    box1.setBox(23);
    box1.setBox(12,34);

    box2.setBox(11);
    box2.setBox(12,32);

    box3 = box1 + box2;
    
    cout<<"box1: ";
    box1.print();
    cout<<"box2: ";
    box2.print();
    cout<<"box3: ";
    box3.print();

    cout<<"\n";
    cout<<"box1: ";
    box1.print();
    cout<<"box1++ : ";
    box1++;
    box1.print();
    cout<<"++box1 : ";
    ++box1;
    box1.print();   
    
    box1.countVol();
    box2.countVol();
    box3.countVol();
    
    
    
    if(box1 < box3)
        cout<<"volume of box1 < box3\n";
    else
        cout<<"volume of box1 > box3\n";
    
    cin>>box3;
    box3.countVol();
    cout<<"box3: " << box3 << endl;

    Box box4;
    box4 = box3;
    box4.countVol();
    cout << box4 <<endl;

    Box box5;
    box5 = box4(3,2,1);
    box5.countVol();
    cout<<"box5: "<< box5 <<endl;
    return 0;
}