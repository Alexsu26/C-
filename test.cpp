#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i;
    vector <int> vec;
    cout<<"vec size = " << vec.size() <<endl;

    for(i=0; i<5; i++)
        vec.push_back(i);
    
    cout<<"after push vec size  " << vec.size() <<endl;

    for(i=0; i<5; i++)
        cout<< "vec[" << i << "] = " << vec[i] <<endl;
    
    return 0;
}