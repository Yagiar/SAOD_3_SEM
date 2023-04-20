#include <iostream>
#include"Test.h"
using namespace std;

int main()
{
    auto p = goo();
    cout << "Val = " << p->Val << endl;
    delete p;
    cout<<"New block:"<<endl;
    std::shared_ptr<Test> t;
{
    auto p1 = foo();
    cout << "Val = " << p1->Val << endl;
    t = p1;
}
cout << "after block" << endl;

}
