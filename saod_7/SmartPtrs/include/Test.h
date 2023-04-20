#include <iostream>
#include <memory>

class Test
{
public:
    Test()
    {
        std::cout << "Test object created" << std::endl;
        Val = 0;
    }

    ~Test()
    {
        std::cout << "Test object destroyed" << std::endl;
    }

    int Val;
};

std::shared_ptr<Test> foo()
{
    auto ptr = std::make_shared<Test>();
    ptr->Val = 42;
    return ptr;
}

Test* goo()
{
    auto ptr = new Test();
    ptr->Val = 42;
    return ptr;
}
