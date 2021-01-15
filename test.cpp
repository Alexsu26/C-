#include <bits.\stdc++.h>
using namespace std;

int main()
{
    vector<int>test;
    int n = 10;
    for(int i=0; i<n; i++)
        test.push_back(i);
    
    test.pop_back();

    for(int i=0; i<test.size(); i++)
        cout<< test[i] << "\n";
    cout<< "test.size() = " << test.size() <<
    "\ntest(9) = " << test[9] << endl;
    return 0;
}